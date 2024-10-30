class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int n = points.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> inMST(n,false);
        int sum = 0;
        pq.push({0,0});

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(inMST[node]) continue;

            sum += wt;
            inMST[node] = true;

            for(auto& vec: adj[node]){
                int nextnode = vec.first;
                int weight = vec.second;

                if(inMST[nextnode] == false){
                    pq.push({weight,nextnode});
                }
            }

        }
        return sum;
    }
};
