class Solution {
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<long long> result(n,LLONG_MAX);
        vector<int> count(n,0);

        for(auto& road: roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        result[0] = 0;
        count[0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            for(auto& p: adj[node]){
                int nextnode = p.first;
                int d = p.second;

                if(dist + d < result[nextnode]){
                    result[nextnode] = dist+d;
                    pq.push({d+dist,nextnode});
                    count[nextnode] = (count[node]%M);
                }
                else if(dist+d == result[nextnode]){
                    count[nextnode] = (count[nextnode] + count[node])%M;
                }
            }
        }

        return count[n-1];
    }
};
