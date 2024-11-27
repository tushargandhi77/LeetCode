class Solution {
public:
    int BFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited,int n){
        queue<int> que;
        que.push(0);
        visited[u] = true;
        int level = 0;
        while(!que.empty()){
            int N = que.size();
            while(N--){
                int Node = que.front();
                que.pop();

                if(Node == n-1)  return level;

                for(int& v: adj[Node]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
            level++;

        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(int i = 1;i<n;i++){
            adj[i-1].push_back(i);
        }

        vector<int> result;
        for(auto& vec: queries){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);

            vector<bool> visited(n,false);
            result.push_back(BFS(adj,0,visited,n));
        }

        return result;
    }
};
