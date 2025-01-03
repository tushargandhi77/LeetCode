class Solution {
public:
    void dijsktra(unordered_map<int,vector<pair<int,int>>>& adj,int src,vector<int>& result,int k){
        queue<pair<int,int>> pq;

        pq.push({0,src});
        result[src] = 0;
        int step = 0;
        while(!pq.empty()){
            int N = pq.size();
            if(step > k){
                break;
            }
            while(N-- ){
                int dist = pq.front().first;
                int node = pq.front().second;

                pq.pop();


                for(auto& it: adj[node]){
                    int newnode = it.first;
                    int d = it.second;

                    if(d+dist < result[newnode]){
                        result[newnode] = d + dist;
                        pq.push({d+dist,newnode});
                    }
                }
            }
            step++;
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        vector<int> result(n,INT_MAX);

        for(auto& vec: flights){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            adj[u].push_back({v,wt});
        }

        dijsktra(adj,src,result,k);

        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};
