// DFS

class Solution {
public:
    void DFS(int u,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool>& visited,int maxwt){
        visited[u] = true;

        for(auto& it : adj[u]){
            int v = it.first;
            int wt = it.second;
            if(wt <= maxwt && !visited[v]){
                DFS(v,adj,visited,maxwt);
            }
        }
    }
    bool canwemake(vector<vector<int>>& edges,int& n,int& maxwt,unordered_map<int,vector<pair<int,int>>>& adj){
        vector<bool> visited(n,false);

        DFS(0,adj,visited,maxwt);

        for(int i = 0;i<n;i++){
            if(visited[i] == false) return false;
        }

        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int l = 0;
        int r = INT_MIN;

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[v].push_back({u,wt}); // reverse the graph
            
            r = max(wt,r);
        }

        int result = -1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(canwemake(edges,n,mid,adj)){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return result;
    }
};

// BFS
