class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> costs(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
            costs[i] = -1;
        }

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                Union(parent_u,parent_v);
                costs[parent_u] &= costs[parent_v];
            }

            costs[parent_u] &= wt;
        }

        vector<int> result;
        for(auto& que: query){
            int s = que[0];
            int e = que[1];

            if(s == e){
                result.push_back(0);
            }
            else if(find(s) != find(e)) result.push_back(-1);
            else result.push_back(costs[parent[s]]);
        }

        return result;
    }
};
