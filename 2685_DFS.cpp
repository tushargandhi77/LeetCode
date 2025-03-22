class Solution {
public:
    void dfs(int curr,unordered_map<int,vector<int>>& adj,vector<bool>& visited,int& v,int& e){
        visited[curr] = true;
        v++;
        e += adj[curr].size();

        for(int& next: adj[curr]){
            if(!visited[next]){
                dfs(next,adj,visited,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int result = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                int v = 0;
                int e = 0;
                dfs(i,adj,visited,v,e);
                if((v*(v-1)) == e){
                    result++;
                }
            }
        }
        return result;
    }
};
