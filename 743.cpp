class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& vec:times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);

        pq.push({0,k});
        result[k] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it: adj[node]){
                int adjNode = it.first;
                int dist = it.second;

                if(d+dist < result[adjNode]){
                    result[adjNode] = d+dist;
                    pq.push({d+dist,adjNode});
                } 
            }
        }
        int res = INT_MIN;
        for(int i = 1;i<=n;i++){
            if(result[i] == INT_MAX) return -1;

            if(res < result[i]){
                res = result[i];
            }
        }

        return res;
    }
};
