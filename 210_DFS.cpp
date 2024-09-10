class Solution {
public:
    bool isCycle = false;
    void DFS(unordered_map<int,vector<int>> &adj,int u,vector<bool>& visited,vector<bool>& inRecursion,stack<int>& st){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v:adj[u]){
            if(inRecursion[v] == true){
                isCycle = true;
                return;
            }
            if(!visited[v]) DFS(adj,v,visited,inRecursion,st);
        }
        inRecursion[u] = false;
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(auto& vec:prerequisites ){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        stack<int> st;
        for(int i = 0;i<numCourses;i++){
            if(!visited[i]) DFS(adj,i,visited,inRecursion,st);
        }
        if(isCycle == true) return {};
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
