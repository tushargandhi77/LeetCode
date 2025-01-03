class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;

        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }


    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        parent.resize(n);
        rank.resize(n,1);

        for(int i =0;i<n;i++)
        {
            parent[i] = i;
        }

        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int,vector<int>> val_to_nodes;

        for(int i = 0;i<n;i++)
        {
            int val = vals[i];
            
            val_to_nodes[val].push_back(i);
        }

        int result = n;

        vector<bool> active(n,false);

        for(auto& it: val_to_nodes)
        {
            vector<int> nodes = it.second;

            for(int &u : nodes)
            {
                for(int& v: adj[u])
                {
                    if(active[v]){
                        Union(u,v);
                    }
                }
                active[u] = true;
            }

            vector<int> Y_parents;

            for(int& u : nodes)
            {
                Y_parents.push_back(find(u));
            }

            sort(begin(Y_parents),end(Y_parents));

            int sz = Y_parents.size();

            for(int j = 0;j<sz;j++)
            {
                long long count = 0;

                int curr_parent = Y_parents[j];

                while(j<sz && Y_parents[j] == curr_parent)
                {
                    j++;
                    count++;
                }
                j--;

                result += (count*(count-1))/2;
            }
        }
        return result;
    }
};
