class Solution {
public:
    bool DFS(int u,int target, unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        visited[u] = true;

        bool ans = false;
        for(int& v : adj[u]){
            if(!visited[v]){
                if(v == target) return true;
                ans = ans | DFS(v,target,adj,visited);
            }
        }

        return ans;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n+1,false);

            if(adj.count(u) && adj.count(v) && DFS(u,v,adj,visited)) return edge;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
