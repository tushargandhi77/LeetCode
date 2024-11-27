class Solution {
public:
    void dikstra(unordered_map<int,vector<pair<int,int>>>& adj,int source,int destination,vector<int>& result){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,source});
        result[source] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto& it: adj[node]){
                int next = it.first;
                int d = it.second;

                if(d+dist < result[next]){
                    result[next] = d+dist;
                    pq.push({d+dist,next});
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i = 1;i<n;i++){
            adj[i-1].push_back({i,1});
        }

        vector<int> res;
        for(auto& vec: queries){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back({v,1});
            vector<int> result(n,INT_MAX);

            dikstra(adj,0,n-1,result);

            res.push_back(result[n-1]);
        }
        return res;
    }
};
