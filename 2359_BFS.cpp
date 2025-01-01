class Solution {
public:
    void BFS(vector<int>& edges,int u,vector<int>& dist,vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int U = que.front();
            que.pop();

            int v = edges[U];

            if(v != -1 && visited[v] == false){
                dist[v] = 1 + dist[U];
                visited[v] = true;
                que.push(v);
            }
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

        BFS(edges,node1,dist1,visited1);
        BFS(edges,node2,dist2,visited2);

        int minval = INT_MAX;
        int minidx = -1;

        for(int i = 0;i<n;i++){
            int maxD = max(dist1[i],dist2[i]);

            if(maxD < minval){
                minval = maxD;
                minidx = i;
            }
        }
        return minidx;
    }
};
