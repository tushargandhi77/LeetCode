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

// Rank compression

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        vector<int> costs(n,-1);
        vector<int> result;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                Union(u,v);
                costs[parent_u] &= costs[parent_v];
                costs[parent_v] &= costs[parent_u];
            }

            costs[parent_u] &= wt;
            costs[parent_v] &= wt;

        }

        for(auto& q: query){
            int s = q[0];
            int t = q[1];

            if(s == t){
                result.push_back(0);
            }

            int s_parent = find(s);
            int t_parent = find(t);

            if(s_parent != t_parent){
                result.push_back(-1);
            }
            else{
                result.push_back(costs[s_parent]);
            }
        }

        return result;
    }
};
