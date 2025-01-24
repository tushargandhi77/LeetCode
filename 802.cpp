class Solution {
public:
    bool DFS(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v: adj[u]){
            if(visited[v] == false && DFS(v,adj,visited,inRecursion)) return true;
            if(inRecursion[v] == true) return true;
        }

        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<bool> inRecursion(n,false);

        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int& v: graph[i]){
                adj[i].push_back(v);
            }
        }

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                DFS(i,adj,visited,inRecursion);
            }
        }

        vector<int> result;
        for(int i = 0;i<n;i++){
            if(inRecursion[i] == false){
                result.push_back(i);
            }
        }

        return result;
    }
};
