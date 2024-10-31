class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(parent[x_parent] > parent[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(parent[y_parent] > parent[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int kruskal(vector<vector<int>>& vec){
        int sum = 0;

        for(auto& temp:vec){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int u_parent = find(u);
            int v_parent = find(v);

            if(u_parent != v_parent){
                Union(u,v);
                sum+= wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> vec;

        int n = points.size();

        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                vec.push_back({i,j,dist});
            }
        }

        auto lamb = [&](auto& v1,auto& v2){
            return v1[2] < v2[2];
        };

        sort(begin(vec),end(vec),lamb);

        return kruskal(vec);
    }
};
