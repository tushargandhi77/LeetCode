class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(n,0);

        for(int u = 0;u<n;u++){
            for(int& v : graph[u]){
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> que;
        for(int i = 0;i<n;i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        vector<bool> isSafe(n,false);

        while(!que.empty()){
            int node = que.front();
            que.pop();
            isSafe[node] = true;

            for(int& v: adj[node]){
                inDegree[v]--;

                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
        
        vector<int> result;
        for(int i = 0;i<n;i++){
            if(isSafe[i] == true){
                result.push_back(i);
            }
        }
        return result;
    }
};
