class Solution {
public:
    void DFS(vector<int>& adj,int u,vector<int>& dist,vector<bool>& visited){
        visited[u] = true;

        int v = adj[u];

        if(v != -1 && !visited[v]){
            dist[v] = 1 + dist[u];
            DFS(adj,v,dist,visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        dist1[node1] = 0;
        dist2[node2] = 0;
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        DFS(edges,node1,dist1,visited1);
        DFS(edges,node2,dist2,visited2);
    
        int minidx=-1;
        int minval = INT_MAX;
        for(int i = 0;i<n;i++){
            int maxD = max(dist1[i],dist2[i]);

            if(maxD < minval){
                minidx = i;
                minval = maxD;
            }
        }
        return minidx;
    }
};
