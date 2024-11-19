//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    void DFS(vector<int>adj[],int u,vector<bool>& visited){
        visited[u] = true;
        
        for(int& v: adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
    }
    bool isConnected(vector<int>adj[],int V){
        int degree = -1;
        
        for(int i = 0;i<V;i++){
            if(adj[i].size() > 0){
                degree = i;
                break;
            }
        }
        
        vector<bool> visited(V,false);
        DFS(adj,degree,visited);
        
        for(int i = 0;i<V;i++){
            if(visited[i] == false && adj[i].size() > 0){
                return false;
            }
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    
	    
	    // Code here
	    
	    if(isConnected(adj,V) == false) return 0;
	    
	    int countodd = 0;
	    
	    for(int i = 0;i<V;i++){
	        if(adj[i].size() % 2 != 0) countodd++;
	    }
	    
	    if(countodd > 2) return 0;
	    
	    if(countodd == 2) return 1;
	    
	    return 2;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
