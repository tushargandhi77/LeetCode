// Method 1:- Dikstar TLE

class Solution {
public:
    long long Dikstra(char s,char d,unordered_map<char,vector<pair<char,int>>>& adj){
        vector<long long> result(26,LLONG_MAX);
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;

        pq.push({0,s});
        result[s-'a'] = 0LL;

        while(!pq.empty()){
            int d = pq.top().first;
            char node = pq.top().second;
            pq.pop();

            for(auto& it: adj[node]){
                char newnode = it.first;
                int dist = it.second;

                if((long long)d + dist < result[newnode-'a']){
                    result[newnode-'a'] = (long long)(d + dist);
                    pq.push({d+dist,newnode});
                }
            }
        }

        return result[d - 'a'];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> adj;
        
        int n = original.size();

        for(int i = 0;i<n;i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }

        long long result = 0LL;

        int m = source.length();

        for(int i = 0;i<m;i++){
            if(source[i] == target[i]) continue;
            if(Dikstra(source[i],target[i],adj) == LLONG_MAX) return -1;

            result += Dikstra(source[i],target[i],adj);
        }

        return result;
    }
};


// Method 2 : - >

class Solution {
public:
    
    void Dikstra(char& ch,unordered_map<char,vector<pair<char,int>>>& adj,vector<vector<long long>>& result){
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;

        result[ch-'a'][ch-'a'] = 0;

        pq.push({0,ch});


        while(!pq.empty()){
            int d = pq.top().first;
            char node = pq.top().second;

            pq.pop();

            for(auto it: adj[node]){
                char adjnode = it.first;
                int dist = it.second;

                if(d + dist < result[ch-'a'][adjnode-'a']){
                    result[ch-'a'][adjnode-'a'] = d + dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> adj;

        for(int i = 0;i<original.size();i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }

        vector<vector<long long>> result(26,vector<long long>(26,INT_MAX));

        for(char ch: source){
            Dikstra(ch,adj,result);
        }

        long long res = 0LL;
        for(int i = 0;i<source.length();i++){
            if(source[i] == target[i]) continue;

            if(result[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;

            res += result[source[i] - 'a'][target[i] - 'a'];
        }

        return res;


    }
};


// Method 3 : - Floyd Warshell


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> grid(26,vector<long long>(26,1e9));

        for(int i = 0;i<26;i++){
            grid[i][i] = 0;
        }
        for(int i = 0;i<original.size();i++){
            grid[original[i]-'a'][changed[i]-'a'] = min(grid[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }

        // floyed warshell
        for(int via = 0;via<26;via++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    grid[i][j] = min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }

        long long result = 0;

        for(int i = 0;i<source.length();i++){
            if(grid[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;

            result += grid[source[i] - 'a'][target[i] - 'a'];
        }

        return result;
    }
};
