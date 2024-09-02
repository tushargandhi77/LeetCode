class Solution {
public:
    void DFS(map<int,vector<int>> adj,int u,vector<bool>& visited){
        visited[u] = true;

        for(auto & v  : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                DFS(adj,i,visited);
                count ++;
            }
        }
        return count;
    }
};
