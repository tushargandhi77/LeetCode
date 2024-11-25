class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(auto& vec: edges){
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<int> que;
        vector<bool> visited(n);

        que.push(source);
        visited[source] = true;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int& v: mp[node]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }

        }
        return visited[destination];
    }
};
