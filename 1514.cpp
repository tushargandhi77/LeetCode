// 2.0
class Solution {
public:
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;

        vector<double> result(n,0);

        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<P> pq; // max

        result[start] = 1;
        pq.push({1.0,start});

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto & temp: adj[currNode]){
                double adjProb = temp.second;
                int ajdNode = temp.first;

                if(result[ajdNode] < currProb*adjProb){
                    result[ajdNode] = currProb*adjProb;
                    pq.push({result[ajdNode],ajdNode});
                }
            }
        }
        return result[end];
    }
};
