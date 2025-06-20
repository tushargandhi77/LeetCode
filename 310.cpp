// BFS 
class Solution {
public:

    int BFS(int u,vector<int>& visited,unordered_map<int,vector<int>>& adj){
        queue<int> que;

        que.push(u);
        visited[u] = true;

        int level = 0;

        while(!que.empty()){
            int N = que.size();
            while(N--){
                int U = que.front();
                que.pop();

                for(int& v: adj[U]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result(n);
        unordered_map<int,vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0;i<n;i++){
            vector<int> visited(n,false);
            int path = BFS(i,visited,adj);
            result[i] = path;
        }

        int min_path = *min_element(begin(result),end(result));
        vector<int> res;

        for(int i = 0;i<n;i++){
            if(result[i] == min_path){
                res.push_back(i);
            }
        }

        return res;
    }
};


// DFS

class Solution {
public:

    int DFS(int u,vector<int>& visited,unordered_map<int,vector<int>>& adj){
       visited[u] = true;

       int max_depth = 0;

       for(int& v: adj[u]){
        if(!visited[v]){
            int depth = DFS(v,visited,adj);
            max_depth = max(depth,max_depth);
        }
       }

       return max_depth+1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result(n);
        unordered_map<int,vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0;i<n;i++){
            vector<int> visited(n,false);
            int path = DFS(i,visited,adj);
            result[i] = path;
        }

        int min_path = *min_element(begin(result),end(result));
        vector<int> res;

        for(int i = 0;i<n;i++){
            if(result[i] == min_path){
                res.push_back(i);
            }
        }

        return res;
    }
};


// Optimual Topological Sort Kahn algo

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> indegree(n);
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> que;
        vector<int> result;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 1){
                que.push(i);
            }
        }

        while(n > 2){
            int size = que.size();
            n -= size;

            while(size--){
                int u = que.front();
                que.pop();
                for(int&v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        que.push(v);
                    }
                }
            }
        }

        while(!que.empty()){
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};
