class Solution {
public:
    bool DFS(unordered_map<int,vector<int>>& adj,int src,int dest,vector<bool>& visited){
        visited[src] = true;

        if(src == dest) return true;

        bool iscourse = false;

        for(int& v : adj[src]){
            if(!visited[v]){
                iscourse = iscourse | DFS(adj,v,dest,visited);
            }
        }

        return iscourse;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> result(Q,false);

        for(int i = 0;i<Q;i++){
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(numCourses,false);
            result[i] = DFS(adj,u,v,visited);
        }
        return result;
    }
};
