class Solution {
public:
    void DFS(int u,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool>& visited,int& cost){
        visited[u] = true;

        for(auto& it: adj[u]){
            int v = it.first;
            int c = it.second;
            if(!visited[v]){
                cost += c;
                DFS(v,adj,visited,cost);
            }
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& vec: connections){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        int cost = 0;
        vector<bool> visited(n,false);
        DFS(0,adj,visited,cost);
        return cost;
    }
};
