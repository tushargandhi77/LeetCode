class Solution {
public:
    bool BFS(unordered_map<int,vector<int>>& adj,int u,vector<int>& color,int currcolor){
        queue<int> que;
        que.push(u);
        color[u] = currcolor;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int& v: adj[node]){
                if(color[v] == color[node]) return false;

                if(color[v] == -1){
                    color[v] = 1 - color[node];
                    que.push(v);
                }
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
                if(BFS(adj,i,color,1) == false) return false;
            }
        }

        return true;
    }
};
