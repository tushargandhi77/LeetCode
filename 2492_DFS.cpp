class Solution {
public:
    void DFS(unordered_map<int,vector<pair<int,int>>>& adj,vector<bool>& visited,int u,int& result){
        visited[u] = true;

        for(auto& V: adj[u]){
            int v = V.first;
            int dist = V.second;
            
            result = min(result,dist);
            if(!visited[v]){
                DFS(adj,visited,v,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> visited(n+1,false);
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& vec : roads){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        int result = INT_MAX;

        DFS(adj,visited,1,result);

        return result;
    }
};
