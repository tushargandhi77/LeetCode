//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    vector<int> parent;
    vector<int> size;
    
    int find(int x){
        if(x==parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent) return;
        
        if(size[x_parent] > size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        if(size[x_parent] < size[y_parent]){
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
        else{
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    size.resize(V);
	    
	    for(int i = 0;i<V;i++){
	        parent[i] = i;
	        size[i] = 1;
	    }
	    
	    for(int u = 0;u<V;u++){
	        for(auto& v:adj[u]){
	            if(u<v){
	                int u_parent = find(u);
	                int v_parent = find(v);
	                
	                if(u_parent == v_parent){
	                    return 1;
	                }
	                Union(u,v);
	            }
	        }
	    }
	    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
