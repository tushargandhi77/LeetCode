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
