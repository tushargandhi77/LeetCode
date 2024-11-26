class Solution {
public: 
    void DFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited){
        visited[u] = true;

        for(int & v: adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
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
        DFS(adj,0,visited);

        for(int i =0;i<n;i++){
            if(visited[i] == false) return false;
        }
        return true;
    }
};
