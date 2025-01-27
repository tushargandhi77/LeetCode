class Solution {
public:
    bool DFS(unordered_map<int,vector<int>>& adj,int src,int dest,vector<bool>& visited){
        visited[src] = true;

        if(src == dest) return true;
        
        bool iscourse = false;
        for(int& v: adj[src]){
            if(!visited[v]){
                iscourse = iscourse | DFS(adj,v,dest,visited);
            }
        } 
        return iscourse;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> grid(numCourses,vector<bool>(numCourses,false));
        unordered_map<int,vector<int>> adj;

        for(auto& vec: prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        for(int i = 0;i<numCourses;i++){
            for(int j = 0;j<numCourses;j++){
                if(i == j) continue;
                vector<bool> visited(numCourses,false);
                grid[i][j] = DFS(adj,i,j,visited);
            }
        }

        int Q = queries.size();
        vector<bool> result(Q,false);

        for(int i = 0;i<Q;i++){
            int u = queries[i][0];
            int v = queries[i][1];

            result[i] = grid[u][v];
        }

        return result;
    }
};
