class Solution {
public:
    int N;

    class DSU{
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){
            parent.resize(n);
            rank.resize(n);

            for(int i = 0;i<n;i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x){
            if(x == parent[x]) return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int x,int y){
            int parent_x = find(x);
            int parent_y = find(y);

            if(parent_x == parent_y) return;

            if(rank[parent_x] > rank[parent_y]){
                parent[parent_x] = parent_y;
            }
            else if(rank[parent_x] < rank[parent_y]){
                parent[parent_y] = parent_x;
            }
            else{
                parent[parent_y] = parent_x;
                rank[parent_y]++;
            }
        }
    };

    int kruskal(vector<vector<int>>& edges,int skip,int add){
        
        int sum = 0;
        DSU dsu(N);
        if(add != -1){
            dsu.Union(edges[add][0],edges[add][1]);
            sum += edges[add][2];
        }

        for(int i = 0;i<edges.size();i++){
            if(i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            int parent_u = dsu.find(u);
            int parent_v = dsu.find(v);

            if(parent_u != parent_v){
                dsu.Union(u,v);
                sum += wt;
            }

        }

        for(int i = 0;i<N;i++){
            if(dsu.find(i) != dsu.find(0)){
                return INT_MAX;
            }
        }

        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;

        for(int i = 0;i<edges.size();i++){
            edges[i].push_back(i);
        }

        auto lambda = [&](auto& vec1,auto& vec2){
            return vec1[2] < vec2[2];
        };

        sort(begin(edges),end(edges),lambda);

        int MST = kruskal(edges,-1,-1);
        vector<int> critical;
        vector<int> psdcritical;

        for(int i = 0;i<edges.size();i++){
            if(kruskal(edges,i,-1) > MST){
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(edges,-1,i) == MST){
                psdcritical.push_back(edges[i][3]);
            }
        }

        return {critical,psdcritical};
    }
};
