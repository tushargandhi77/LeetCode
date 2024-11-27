class Solution {
public:
    bool DFS(unordered_map<int,vector<int>>& adj,int u,vector<int>& color,int currcolor){
        color[u] = currcolor;

        for(int & v: adj[u]){
            if(color[v] == color[u]) return false;

            if(color[v] == -1){
                int colorv = 1 - currcolor;
                if(DFS(adj,v,color,colorv) == false) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;

        for(auto& vec: dislikes){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i = 1;i<=n;i++){
            if(color[i] == -1){
                if(DFS(adj,i,color,1) == false) return false;
            }
        }

        return true;
    }
};
