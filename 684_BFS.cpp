class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>& adj,int u,int end,vector<bool>& visited){
        queue<int> que;
        que.push(u);

        visited[u] = true;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            if(node == end) return true;

            for(int& v: adj[node]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int,vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n+1,false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && bfs(adj,u,v,visited)){
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};
