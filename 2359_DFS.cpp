class Solution {
public:
    int n;
    void dfs(int u,vector<bool>& visited,vector<int>& dist,vector<int>& edges){
        visited[u] = true;

        int v = edges[u];

        if(v != -1 && !visited[v]){
            dist[v] = 1 + dist[u];
            dfs(v,visited,dist,edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1,visited1,dist1,edges);
        dfs(node2,visited2,dist2,edges);

        int minindex = -1;
        int minnode = INT_MAX;

        for(int i = 0;i<n;i++){
            int maxD = max(dist1[i],dist2[i]);
            if(maxD < minnode){
                minnode = maxD;
                minindex = i;
            }
        }

        return minindex;
    }
};
