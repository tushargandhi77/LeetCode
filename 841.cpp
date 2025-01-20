class Solution {
public:
    void DFS(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        visited[u] = true;

        for(auto& v : adj[u]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int & v: rooms[i]){
                adj[i].push_back(v);
            }
        }

        vector<bool> visited(n,false);
        DFS(0,adj,visited);

        for(int i = 0;i<n;i++){
            if(visited[i] == false) return false;
        }

        return true;
    }
};
