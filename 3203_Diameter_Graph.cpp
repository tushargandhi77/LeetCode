class Solution {
public:
    unordered_map<int,vector<int>> buildadj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int findDiameter(unordered_map<int,vector<int>>& adj){
        // step 1 find the  farthes nodes form random nodes

        auto [farthestNode,dist] = BFS(adj,0);

        // step 2 farthestNodes is one node of farhtes nodes
        auto [otherEndNode,diameter] = BFS(adj,farthestNode);
        // step 3 find the farthes nodes from the above node

        return diameter;

    }

    pair<int,int> BFS(unordered_map<int,vector<int>>& adj,int source){
        queue<int> que;
        que.push(source);

        unordered_map<int,bool> visited;
        visited[source] = true;

        int dist = 0;
        int farthestNode = source;

        while(!que.empty()){
            int size = que.size();
            while(size--){
                int curr = que.front();
                que.pop();

                farthestNode = curr;

                for(auto& nbr : adj[curr]){
                    if(visited[nbr] == false){
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if(!que.empty()) dist++;
        }
        return {farthestNode,dist};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = buildadj(edges1);
        unordered_map<int,vector<int>> adj2 = buildadj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combine = (d1+1)/2 + (d2+1)/2 + 1;
        return max({d1,d2,combine});
    }
};
