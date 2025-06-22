// Method 1 - > Brute Force TLE
class Solution {
public:

    bool DFS(int u,int target,unordered_map<int,vector<int>>& adj){
        if(u == target) return true;

        for(int& v: adj[u]){
            if(DFS(v,target,adj) == true) return true;
        }

        return false;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for(int u = 0;u<n;u++){
            for(int v = 0;v<n;v++){
                if(u == v) continue;
                if(DFS(u,v,adj)){
                    result[v].push_back(u);
                }
            }
        }

        return result;
    }
};
