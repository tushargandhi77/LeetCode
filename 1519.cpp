class Solution {
public:
    void DFS(unordered_map<int,vector<int>>& adj,int curr,int parent,vector<int>& result,vector<int>& count,string& labels){
        char ch = labels[curr];

        int count_before = count[ch-'a'];

        count[ch-'a'] += 1;

        for(auto& v: adj[curr]){
            if(v == parent) continue;

            DFS(adj,v,curr,result,count,labels);
        }

        int count_after = count[ch-'a'];

        result[curr] = count_after - count_before;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n,0);
        vector<int> count(26,0);

        DFS(adj,0,-1,result,count,labels);
        return result;
    }
};
