class Solution {
public:
    void DFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited){
        visited[u] = true;

        for(int& v: adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;

        for(auto& vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n);

        DFS(adj,source,visited);

        return visited[destination];
    }
};
