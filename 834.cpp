class Solution {
public:
    long root_count;
    int N;
    vector<int> count;

    int DFSBase(unordered_map<int,vector<int>>& adj,int curr,int parent,int depth){
        int total_count = 1;

        root_count += depth;

        for(auto& child: adj[curr]){
            if(child == parent) continue;

            total_count += DFSBase(adj,child,curr,depth+1);
        }

        count[curr] = total_count;
        return total_count;
    }

    void DFS(unordered_map<int,vector<int>>& adj,int curr,int parent,vector<int>& result){
        for(int& child: adj[curr]){
            if(child == parent) continue;

            result[child] = result[curr] - count[child] + (N - count[child]);

            DFS(adj,child,curr,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        root_count = 0;
        count.resize(n,0);

        unordered_map<int,vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFSBase(adj,0,-1,0);

        vector<int> result(n,0);
        result[0] = root_count;

        DFS(adj,0,-1,result);

        return result;
    }
};
