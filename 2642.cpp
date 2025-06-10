// Method 1 :- Dikstra Algo

class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int N;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto& edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(N,INT_MAX);

        pq.push({0,node1});
        result[node1] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto& it : adj[node]){
                int  newnode = it.first;
                int dist = it.second;

                if(d+dist < result[newnode]){
                    result[newnode] = d + dist;
                    pq.push({d+dist,newnode});
                }
            }
        }
        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


// Method 2 :- Floyd Warshell


class Graph {
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n,vector<int>(n,1e9));

        // node -> node = 0;
        for(int i = 0;i<n;i++){
            adj[i][i] = 0;
        }

        // set edges
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adj[u][v] = cost;
        }

        // floyd Warshall
        for(int via = 0;via<n;via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }


    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                adj[i][j] = min(adj[i][j],adj[i][u] + cost + adj[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
