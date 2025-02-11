class Solution {
public:
    bool isBipartite(unordered_map<int,vector<int>>& adj,int curr,vector<int>& colors,int currcolor){
        colors[curr] = currcolor;

        for(int& ngbr : adj[curr]){

            if(colors[ngbr] == colors[curr]) return false;

            if(colors[ngbr] == -1 ){
                if(isBipartite(adj,ngbr,colors,1-currcolor) == false){
                    return false;
                }
            }
        }

        return true;
    }
    int BFS(unordered_map<int,vector<int>>& adj,int currNode,int n){
        queue<int> que;
        vector<bool> visited(n,false);
        que.push(currNode);
        visited[currNode] = true;

        int level = 1;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int curr = que.front();
                que.pop();

                for(auto& ngbr : adj[curr]){
                    if(!visited[ngbr]){
                        que.push(ngbr);
                        visited[ngbr] = true;
                    }
                }
            }
            level++; // one extra will be increamented
        }
        return level-1;
    }
    int getMaxFromGP(unordered_map<int,vector<int>>& adj,int curr,vector<bool>& visited,vector<int>& levels){
        int maxGp = levels[curr];
        visited[curr] = true;

        for(int& ngbr : adj[curr]){
            if(!visited[ngbr]){
                maxGp = max(maxGp,getMaxFromGP(adj,ngbr,visited,levels));
            }
        }
        return maxGp;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0] - 1; // converting to zero based index
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // bipartite check

        vector<int> colors(n,-1);
        for(int node = 0;node<n;node++){
            if(colors[node] == -1){
                if(isBipartite(adj,node,colors,1) == false){
                    return -1;
                }
            }
        }

        // BFS Check
        
        vector<int> levels(n,0);
        for(int node = 0;node<n;node++){
            levels[node] = BFS(adj,node,n);
        }

        int maxGroupEachComp = 0;
        vector<bool> visited(n,false);
        for(int node = 0;node<n;node++){
            if(!visited[node]){
                maxGroupEachComp += getMaxFromGP(adj,node,visited,levels);
            }
        }
        return maxGroupEachComp;
    }
};
