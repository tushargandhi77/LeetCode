// Dikstra Algo

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        d1[1] = 0;

        while(!pq.empty()){
            auto [timepassed,node] = pq.top();
            pq.pop();

            if(node == n && d2[node] != INT_MAX) return d2[node];

            int div = timepassed/change;
            if(div%2 == 1){
                timepassed = (div+1)*change;
            }

            for(int& v: adj[node]){
                if(timepassed+time < d1[v]){
                    d2[v] = d1[v];
                    d1[v] = timepassed+time;
                    pq.push({timepassed+time,v});
                }
                else if(timepassed+time < d2[v] && d1[v] != timepassed+time){
                    d2[v] = timepassed+time;
                    pq.push({timepassed+time,v});
                }
            }
        }

        return -1;
    }
};

// BFS

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);

        queue<pair<int,int>> que;

        que.push({1,1}); // node freq

        d1[1] = 0;

        while(!que.empty()){
            auto [node,freq] = que.front();
            que.pop();

            int timepassed = (freq==1) ? d1[node] : d2[node];

            if(node == n && d2[node] != INT_MAX) return d2[node];

            int div = timepassed / change;
            if(div%2 == 1){
                timepassed = (div+1)*change;
            }

            for(auto& nbr: adj[node]){
                if(d1[nbr] == INT_MAX){
                    d1[nbr] = timepassed+time;
                    que.push({nbr,1});
                }
                else if(d2[nbr] == INT_MAX && d1[nbr] != timepassed+time){
                    d2[nbr] = timepassed+time;
                    que.push({nbr,2});
                }
            }
        }
        return -1;
    }   
};
