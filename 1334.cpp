// Dikstra Algo

class Solution {
public:
    void Dikstra(int s,unordered_map<int,vector<pair<int,int>>>& adj,vector<vector<int>>& result){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,s});
        result[s][s] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto& it: adj[node]){
                int newnode = it.first;
                int dist = it.second;

                if(d + dist < result[s][newnode]){
                    result[s][newnode] = d + dist;
                    pq.push({d+dist,newnode});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        for(int i = 0;i<n;i++){
            Dikstra(i,adj,result);
        }

        int min_pts = INT_MAX;

        for(int i = 0;i<n;i++){
            int count_node = 0;
            for(int j = 0;j<n;j++){
                if(i == j) continue;

                if(result[i][j] <= distanceThreshold){
                    count_node++;
                }
            }

            min_pts = min(min_pts,count_node);
        }

        int final_result = -1;
        for(int i = 0;i<n;i++){
            int count_node = 0;
            for(int j = 0;j<n;j++){
                if(i == j) continue;

                if(result[i][j] <= distanceThreshold){
                    count_node++;
                }
            }

            if(count_node == min_pts) final_result = i;
        }

        return final_result;
    }
};
