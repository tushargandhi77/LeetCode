class Solution {
public:
    void bfs(int curr,unordered_map<int,vector<int>>& adj,vector<bool>& visited,int& V,int& e){
        queue<int> que;

        visited[curr] = true;
        que.push(curr);

        while(!que.empty()){
            int U = que.front();
            que.pop();
            V++;
            e += adj[U].size();

            for(int& v: adj[U]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
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
                bfs(i,adj,visited,v,e);
                if((v*(v-1)) == e){
                    result++;
                }
            }
        }
        return result;
    }
};
