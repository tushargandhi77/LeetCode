class Solution {
public:
    class DSU{
        public:
            vector<int> parent;
            vector<int> size;

            DSU(int n){
                parent.resize(n);
                size.resize(n);
                for(int i = 0 ;i<n;i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }
            int find(int x){
                if(parent[x] == x) return x;

                return parent[x] = find(parent[x]);
            }
            void Union(int x,int y){
                int x_parent = find(x);
                int y_parent = find(y);

                if(x_parent == y_parent) return;
                if(size[x_parent] > size[y_parent]){
                    parent[y_parent] = x_parent;
                    size[x_parent] += size[y_parent];
                }
                else if(size[y_parent] > size[x_parent]){
                    parent[x_parent] = y_parent;
                    size[y_parent] += size[x_parent]; 
                }
                else{
                    parent[y_parent] = x_parent;
                    size[x_parent] += size[y_parent];
                }
            }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        unordered_map<int,int> mp;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            dsu.Union(u,v);
        }

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            int root = dsu.find(u);
            mp[root]++;
        }

        int result = 0;

        for(int i = 0;i<n;i++){
            if(dsu.find(i) == i){
                int v = dsu.size[i];
                int e = mp[i];

                if((v*(v-1))/2 == e){
                    result++;
                }
            }
        }

        return result;
    }
};
