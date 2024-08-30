//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        // code here
        queue<int> que;
        int count = 0;
        
        vector<int> indegree(N,0);
        // create indegree 
        for(int u = 0; u<N ;u++){
            for(int & v: adj[u]){
                indegree[v]++;
            }
        }
        // Fill queue
        for(int i = 0;i<N;i++){
            if(indegree[i] == 0){
                que.push(i);
                count++;
            }
        }
        // BFs
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(int & v:adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count == N){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
