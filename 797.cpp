class Solution {
public:
    vector<vector<int>> result;
    void DFS(vector<vector<int>>& graph,int u,int target, vector<int> path){
        path.push_back(u);
        if(u == (target-1)){
            result.push_back(path);
        }

        for(int &v : graph[u]){
            DFS(graph,v,target,path);
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> path;

        DFS(graph,0,n,path);

        return result;
    }
};
