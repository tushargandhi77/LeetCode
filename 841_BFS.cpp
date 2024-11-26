class Solution {
public: 
    void BFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;
        
        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int& v: adj[node]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int& v: rooms[i]){
                adj[i].push_back(v);
            }
        }
        vector<bool> visited(n,false);
        BFS(adj,0,visited);

        for(int i =0;i<n;i++){
            if(visited[i] == false) return false;
        }
        return true;
    }
};
