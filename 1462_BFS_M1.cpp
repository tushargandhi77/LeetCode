class Solution {
public:
    bool BFS(unordered_map<int,vector<int>>& adj,int src,int dest,vector<bool>& visited){
        queue<int> que;
        que.push(src);
        visited[src] = true;

        bool iscourse = false;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            if(node == dest) iscourse = true;

            for(auto& v : adj[node]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
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
            result[i] = BFS(adj,u,v,visited);
        }
        return result;
    }
};
