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
