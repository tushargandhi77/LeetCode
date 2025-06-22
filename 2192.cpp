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

// Method 2 

class Solution {
public:
    void DFS(int ancestor,int curr,unordered_map<int,vector<int>>& adj,vector<vector<int>>& result){

        for(int& v: adj[curr]){
            if(result[v].empty() || result[v].back() != ancestor){
                result[v].push_back(ancestor);
                DFS(ancestor,v,adj,result);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for(int i = 0;i<n;i++){
            int ansester = i;
            DFS(ansester,i,adj,result);
        }

        return result;
    }
};


// Method 3 

class Solution {
public:
    
    void DFS(int curr,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        visited[curr] = true;

        for(int& v: adj[curr]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        for(int i = 0;i<n;i++){
            vector<bool> visited(n,false);
            DFS(i,adj,visited);

            for(int j = 0;j<n;j++){
                if(i == j) continue;
                if(visited[j]){
                    result[i].push_back(j);
                }
            }
        }

        return result;
    }
};
