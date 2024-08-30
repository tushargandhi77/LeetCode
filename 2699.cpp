class Solution {
public:
    typedef long long ll;
    const int Large_val = 2e9;
    typedef pair<long long,long long> P;
    ll DijkstraAlgo(vector<vector<int>>& edges,int n,int src,int dest){
        unordered_map<ll,vector<pair<ll,ll>>> adj; // u -> {v,wt}

        for(vector<int> & edge : edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});

            }
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<ll> result(n,INT_MAX);
        vector<bool> visited(n,false);

        result[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            ll currdist = pq.top().first;
            ll currnode = pq.top().second;
            pq.pop();

            if(visited[currnode] == true) continue;

            visited[currnode] = true;

            for(auto& [nbr,wt] : adj[currnode]){
                if(result[nbr] > currdist + wt){
                    result[nbr] = currdist + wt;
                    pq.push({result[nbr],nbr});
                }
            }
        }
        return result[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currshortestdist = DijkstraAlgo(edges,n,source,destination);
        if(currshortestdist<target) return {};

        bool matchtarget = (currshortestdist == target);

        if(matchtarget){
            for(vector<int>& edge: edges){
                if(edge[2] == -1){
                    edge[2] = Large_val;
                }
            }
            return edges;
        }

        for(vector<int>& edge:edges){
            if(edge[2] == -1){
                edge[2] = (matchtarget == true) ? Large_val : 1;

                if(matchtarget != true) {
                    ll newshortdist = DijkstraAlgo(edges,n,source,destination);

                    if(newshortdist <= target){
                        matchtarget = true;
                        edge[2] += (target - newshortdist);
                    }
                }
            }
        }

        if(matchtarget == false) return {};
        return edges;
    }
};
