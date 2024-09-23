//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isbipartiteBFS(vector<int>adj[],int u,vector<int>& color,int currcolor){
        queue<int> que;
        que.push(u);
        color[u] = currcolor;
        
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            
            for(int& v:adj[curr]){
                if(color[v] == color[curr]) return false;
                if(color[v] == -1){
                    color[v] = 1 - color[curr];
                    que.push(v);
                }
            }
        }  
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    
	    for(int i = 0; i < V;i++){
	        if(color[i] == -1){
	            if(isbipartiteBFS(adj,i,color,1) == false) return false;
	        }
	    }
	return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
