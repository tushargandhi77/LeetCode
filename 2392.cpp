// DFS

class Solution {
public:
    void DFS(int u ,vector<int>& visited,unordered_map<int,vector<int>>& adj,bool & iscycle,stack<int>& st){
        visited[u] = 1;

        for(int& v: adj[u]){
            if(visited[v] == 0){
                DFS(v,visited,adj,iscycle,st);
            }
            else if(visited[v] == 1){
                iscycle = true;
                return;
            }
        }

        visited[u] = 2;
        st.push(u);
    }
    vector<int> toposort(int n,vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        vector<int> visited(n+1,0);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        bool iscycle = false;
        stack<int> st;

        for(int i = 1;i<=n;i++){
            if(visited[i] == 0){
                DFS(i,visited,adj,iscycle,st);
            }
        }

        if(iscycle) return {};

        vector<int> order;

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }

        return order;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> toporow = toposort(k,rowConditions);
        vector<int> topocol = toposort(k,colConditions);

        if(toporow.empty() || topocol.empty()) return {};

        vector<vector<int>> result(k,vector<int>(k,0));

        for(int i = 0;i<k;i++){
            for(int j = 0;j<k;j++){
                if(toporow[i] == topocol[j]){
                    result[i][j] = toporow[i];
                }
            }
        }

        return result;
    }
};
