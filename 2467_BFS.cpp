class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> BobMp;
    int aliceincome;

    bool DFSBOB(int curr,int t,vector<bool>& visited){
        visited[curr] = true;
        BobMp[curr] = t;

        if(curr == 0){
            return true;
        }

        for(int& ngbr : adj[curr]){
            if(!visited[ngbr]){
                if(DFSBOB(ngbr,t+1,visited)==true){
                    return true;
                }
            }
        }

        BobMp.erase(curr);
        return false;
    }

    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceincome = INT_MIN;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        DFSBOB(bob,0,visited);

        visited.assign(n, false);
        int income = 0;

        // BFS

        queue<vector<int>> que;

        que.push({0,0,0});

        while(!que.empty()){
            int curr = que.front()[0];
            int t = que.front()[1];
            int income = que.front()[2];

            que.pop();

            if(BobMp.find(curr) == BobMp.end() || t < BobMp[curr]){
                income += amount[curr];
            }
            else if(t == BobMp[curr]){
                income += (amount[curr]/2);
            }

            if(adj[curr].size() == 1 && curr != 0){
                aliceincome = max(aliceincome,income);
            }

            for(int& ngbr : adj[curr]){
                if(!visited[ngbr]){
                    que.push({ngbr,t+1,income});
                }
            }
            visited[curr] = true;
        }


        return aliceincome;
    }
};
