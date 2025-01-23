class Solution {
public:
    void DFS(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,long long& size){
        visited[u] = true;
        size++;

        for(int& v: adj[u]){
            if(!visited[v]){
                DFS(v,adj,visited,size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long result = 0;
        long long rem = n;

        for(int i = 0;i<n;i++){
            long long size = 0;
            if(!visited[i]){
                DFS(i,adj,visited,size);
            }

            result += size * (rem - size);
            rem = rem - size;
        }
        return result;
    }
};
