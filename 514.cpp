// Memo 
class Solution {
public:
    int t[101][101];
    int countstep(int rindIdx,int newIdx,int ringlength){
        int followup = abs(newIdx - rindIdx);
        int backward = ringlength - followup;

        return min(followup,backward);
    }
    int solve(int ringIdx,int keyIdx,string& ring,string& key){
        if(keyIdx >= key.length()) return 0;
        
        if(t[ringIdx][keyIdx] != -1) return t[ringIdx][keyIdx];

        int result = INT_MAX;
        for(int i = 0;i<ring.length();i++){
            if(ring[i] == key[keyIdx]){
                int step = 1 + countstep(ringIdx,i,ring.length()); // one for writing
                int total_step = step + solve(i,keyIdx+1,ring,key);

                result = min(total_step,result);
            }
        }
        return t[ringIdx][keyIdx] = result;
    }
    int findRotateSteps(string ring, string key) {
        memset(t,-1,sizeof(t));
        return solve(0,0,ring,key);
    }
};

// Bottom Up 

class Solution {
public:
    int countstep(int rindIdx,int newIdx,int ringlength){
        int followup = abs(newIdx - rindIdx);
        int backward = ringlength - followup;

        return min(followup,backward);
    }
    
    int findRotateSteps(string ring, string key) {
       int n = ring.length();
       int m = key.length();

       vector<vector<int>> t(n,vector<int>(m+1,0));

       // base case
       for(int i = 0;i<n;i++){
            t[i][m] = 0;
       }

       for(int keyIdx = m-1;keyIdx>=0;keyIdx--){
        for(int ringIdx = 0;ringIdx < n; ringIdx++){
            int result = INT_MAX;
            for(int i = 0;i<n;i++){
                if(ring[i] == key[keyIdx]){
                    int total_step = 1 + countstep(ringIdx,i,n) + t[i][keyIdx+1];

                    result = min(result,total_step);
                }
            }

            t[ringIdx][keyIdx] = result;
        }
       }

       return t[0][0];
    }
};

// Dikstra Algo

class Solution {
public:
    int countsteps(int ringIdx,int idx,int n){
        int dist = abs(idx - ringIdx);
        int wraparound = n - dist;

        return min(dist,wraparound);
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        unordered_map<char,vector<int>> adj;

        for(int i = 0;i<n;i++){
            char ch = ring[i];
            adj[ch].push_back(i);
        }

        int totalsteps = 0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        set<pair<int,int>> visited;

        pq.push({0,0,0});

        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();

            totalsteps = vec[0];
            int rIdx = vec[1];
            int kIdx = vec[2];
            char ch = key[kIdx];

            if(kIdx == m) break;

            if(visited.count({rIdx,kIdx})) continue;

            visited.insert({rIdx,kIdx});

            for(int& nextstep: adj[ch]){
                int steps = countsteps(rIdx,nextstep,n) + totalsteps;
                pq.push({steps,nextstep,kIdx+1});
            }

        }

        return totalsteps + m;
    }
};
