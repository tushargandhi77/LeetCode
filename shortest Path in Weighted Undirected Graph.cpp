//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> parent(n+1);
        vector<int> result(n+1,INT_MAX);
        
        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        
        pq.push({0,1});
        result[1] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto& vec: adj[node]){
                int newNode = vec.first;
                int dist = vec.second;
                
                if(d+dist < result[newNode]){
                    result[newNode] = d+dist;
                    pq.push({d+dist,newNode});
                    
                    parent[newNode] = node;
                }
            }
        }
        if(result[n] == INT_MAX) return {-1};
        vector<int> res;
        
        int target = n;
        while(parent[target] != target){
            res.push_back(target);
            
            target = parent[target];
        }
        res.push_back(1);
        reverse(begin(res),end(res));
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
