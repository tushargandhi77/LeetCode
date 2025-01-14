class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& vec: roads){
            int u = vec[0];
            int v = vec[1];
            int dist = vec[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<int> visited(n+1,false);

        queue<int> que;
        que.push(1);
        visited[1] = true;

        int result = INT_MAX;
        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(auto& V : adj[node]){
                int v = V.first;
                int dist = V.second;

                result = min(result,dist);
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }            
        }
        return  result;
    }
};
