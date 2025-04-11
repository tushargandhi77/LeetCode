class Solution {
public:
    void DFS(int u,unordered_set<int>& visited,unordered_map<int,vector<int>>& adj){
        visited.insert(u);

        for(int& v: adj[u]){
            if(visited.find(v) == visited.end()){
                DFS(v,visited,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;

                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long r2 = bombs[j][2];

                long long dist = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

                if((long long)r1*r1 >= dist){
                    adj[i].push_back(j);
                }
            }
        }


        unordered_set<int> visited;
        int result = INT_MIN;
        for(int i = 0;i<n;i++){
            DFS(i,visited,adj);
            int count = visited.size();
            result = max(result,count);
            visited.clear();
        }
        return result;
    }
};
