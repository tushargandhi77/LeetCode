class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = grid.size();
        int n = grid[0].size();

        auto isafe = [&](int x,int y){
            if(x >= 0 && x < m && y >= 0 && y < n){
                return true;
            }
            else{
                return false;
            }
        };

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        vector<vector<int>> visited(m,vector<int>(n,false));
        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({grid[0][0],{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(visited[i][j] == true) continue;

            visited[i][j] = true;

            for(auto& vec:directions){
                int x = vec[0] + i;
                int y = vec[1] + j;

                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;

                if(grid[x][y]  <= dist+1){
                    pq.push({dist+1,{x,y}});
                    result[x][y] = dist+1;
                }
                else if((grid[x][y] - dist)%2 == 0){
                    pq.push({grid[x][y]+1,{x,y}});
                    result[x][y] = grid[x][y] + 1;
                }
                else{
                    pq.push({grid[x][y],{x,y}});
                    result[x][y] = grid[x][y];
                }
            }
        }
        return result[m-1][n-1];
    }
};
