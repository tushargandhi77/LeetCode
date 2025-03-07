class Solution {
public:
    int result = -1;

    void DFS(int u,vector<int>& edges,vector<bool>& visited,vector<int>& count,vector<bool>& inRecursion){
        if(u != -1){
            visited[u] = true;
            inRecursion[u] = true;

            int v = edges[u];

            if(v != -1 && visited[v] == false){
                count[v] = 1 + count[u];
                DFS(v,edges,visited,count,inRecursion);
            }
            else if(v != -1 && inRecursion[v] == true){
                result = max(result,count[u]-count[v]+1);
            }
            inRecursion[u] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<bool> visited(n,false);
        vector<bool> inRecursion(n,false);
        vector<int> count(n,1);

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                DFS(i,edges,visited,count,inRecursion);
            }
        }

        return result;
    }
};
