// TLE
class Solution {
public:

    int DFS(int i,int parent,int power,unordered_map<int,vector<int>>& adj,vector<int>& coins, int k){
        int case1 = (coins[i] >> power) - k; // coins[i]/(1<<power)
        int case2 = (coins[i] >> (power+1));

        for(int ngbr: adj[i]){
            if(parent != ngbr){
                case1 += DFS(ngbr,i,power,adj,coins,k);
                case2 += DFS(ngbr,i,power+1,adj,coins,k);
            }
        }

        return max(case1,case2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return DFS(0,-1,0,adj,coins,k);
    }
};
