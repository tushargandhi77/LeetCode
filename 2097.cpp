class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for(auto& edge: pairs){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        int start = pairs[0][0];

        for(auto& it: adj){
            int node = it.first;

            if((outdegree[node] - indegree[node] == 1)){
                start = node;
                break;
            }
        }
        
        vector<int> Eulerpath;
        stack<int> st;
        st.push(start);

        while(!st.empty()){
            int curr = st.top();

            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                Eulerpath.push_back(curr);
                st.pop();
            }
        }
        reverse(begin(Eulerpath),end(Eulerpath));

        vector<vector<int>> result;
        for(int i = 1;i<Eulerpath.size();i++){
            result.push_back({Eulerpath[i-1],Eulerpath[i]});
        }
        return result;
    }
};
