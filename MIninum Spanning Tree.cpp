//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> inMST(V,false);
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(inMST[node]) continue;
            
            inMST[node] = true;
            sum += wt;
            
            for(auto& vec: adj[node]){
                int nbr = vec[0];
                int weight = vec[1];
                
                if(inMST[nbr] == false){
                    pq.push({weight,nbr});
                    
                }
            }
        }
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends
