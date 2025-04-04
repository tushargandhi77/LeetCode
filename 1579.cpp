class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            components = n;
            for(int i = 1;i<=n;i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x){
            if(x == parent[x]) return x;

            return find(parent[x]);
        }

        void Union(int x,int y){
            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent == y_parent) return;

            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[y_parent] > rank[x_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            
            components--;
        }

        bool isSingleComponent(){
            return components == 1;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        auto lambda = [](auto& vec1, auto& vec2){
            return vec1[0] > vec2[0];
        };

        sort(begin(edges),end(edges),lambda);

        int edgeCount = 0;

        for(auto& vec: edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type == 3){
                bool addEdge = false;

                if(alice.find(u) != alice.find(v)){
                    alice.Union(u,v);
                    addEdge = true;
                }
                if(bob.find(u) != bob.find(v)){
                    bob.Union(u,v);
                    addEdge = true;
                }
                if( addEdge == true){
                    edgeCount++;
                }
            }
            else if(type == 2){
                if(bob.find(u) != bob.find(v)){
                    bob.Union(u,v);
                    edgeCount++;
                }
            }
            else{
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u,v);
                    edgeCount++;
                }
            }
        }
        
        if(alice.isSingleComponent() == true && bob.isSingleComponent()){
            return edges.size() - edgeCount;
        }

        return -1;
    }
};
