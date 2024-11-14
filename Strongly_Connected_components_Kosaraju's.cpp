//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void Dfsfill(int u,vector<vector<int>>& adj,vector<bool>& visited,stack<int>& st){
	    visited[u] = true;
	    
	    for(int& v: adj[u]){
	        if(!visited[v]){
	            Dfsfill(v,adj,visited,st);
	        }
	    }
	    st.push(u);
	}
	void DFS(int u,vector<vector<int>>& adj,vector<bool>& visited){
	    visited[u] = true;
	    
	    for(int& v: adj[u]){
	        if(!visited[v]){
	            DFS(v,adj,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // step 1 topo order
        
        stack<int> st;
        vector<bool> visited(V,false);
        
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                Dfsfill(i,adj,visited,st);
            }
        }
        
        // step 2 reverse a adj
        vector<vector<int>> reverseadj(V);
        
        for(int u = 0;u<V;u++){
            for(int& v: adj[u]){
                reverseadj[v].push_back(u);
            }
        }
        
        // step 3
        
        visited = vector<bool>(V,false);
        int ssc_count = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                DFS(node,reverseadj,visited);
                ssc_count++;
            }
        }
        
        return ssc_count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends
