//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        
        vector<int> result(V,INT_MAX);
        st.insert({0,S});
        result[S] = 0;
        
        while(!st.empty()){
            auto& it = *st.begin();
            int d = it.first;
            int Node = it.second;
            st.erase(it);
            
            for(auto& vec: adj[Node]){
                int currNode = vec[0];
                int dist = vec[1];
                
                if(d+dist < result[currNode]){
                    
                    if(result[currNode] != INT_MAX){
                        st.erase({result[currNode],currNode});
                    }
                    
                    result[currNode] = d+dist;
                    st.insert({d+dist,currNode});
                }
            }
        }
        return result;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
