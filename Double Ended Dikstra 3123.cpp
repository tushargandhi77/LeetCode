class Solution {
public:
    int N;

    vector<int> Dikstra(int source,unordered_map<int,vector<pair<int,int>>>& adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(N,INT_MAX);

        result[source] = 0;
        pq.push({0,source});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& it: adj[node]){
                int newnode = it.first;
                int dist = it.second;

                if(d+dist < result[newnode]){
                    result[newnode] = d + dist;
                    pq.push({d+dist,newnode});
                }
            }
        }
        return result;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        N = n;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int> ZeroToN = Dikstra(0,adj);
        vector<int> NTo0 = Dikstra(N-1,adj);

        long long sortestPath = (long long)NTo0[0];

        vector<bool> result;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            long long resultantpath1 = (long long)ZeroToN[u] + wt + NTo0[v];
            long long resultantpath2 = (long long)ZeroToN[v] + wt + NTo0[u];

            if(resultantpath1 == sortestPath || resultantpath2 == sortestPath){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};
