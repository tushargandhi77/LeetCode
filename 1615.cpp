class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int result = INT_MIN;

        unordered_map<int,unordered_set<int>> adj;
        for(auto& vec: roads){
            int u = vec[0];
            int v = vec[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int i_rank = adj[i].size();
                int j_rank = adj[j].size();
                int total = i_rank+j_rank;
                if(adj[i].find(j) != adj[i].end()){
                    total--;
                }

                result = max(total,result);
            }
        }

        return result;
    }
};
