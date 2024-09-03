class Solution {
public:
    void BFS(unordered_map<int,vector<int>> adj,int u , vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int & v : adj[curr]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int,vector<int>> adj;

        // make graph
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n,false);
        for(int  i = 0;i<n;i++){
            if(!visited[i]){
                BFS(adj,i,visited);
                count ++;
            }
        }
        return count;
    }
};
