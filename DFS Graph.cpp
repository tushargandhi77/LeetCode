//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<int> adj[],int u,vector<bool>& visited,vector<int>& result){
        visited[u] = true; 
        result.push_back(u);
        
        for(auto& v:adj[u]){
            if(!visited[v]) DFS(adj,v,visited,result);
        }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> result;
        
        for(int i = 0;i<V;i++){
            if(!visited[i]) DFS(adj,i,visited,result);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
