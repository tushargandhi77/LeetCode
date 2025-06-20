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
