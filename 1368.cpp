class Solution {
public:
    int m,n;
    
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    void dijstra(vector<vector<int>>& grid,vector<vector<int>>& result){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        result[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int wt = curr[0];
            int x = curr[1];
            int y = curr[2];

            for(int i = 0;i<=3;i++){
                int x_ = x + dir[i][0];
                int y_ = y + dir[i][1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n){
                    int nextwt = (grid[x][y]-1 != i ? 1 : 0);

                    if(nextwt + wt < result[x_][y_]){
                        result[x_][y_] = nextwt + wt;
                        pq.push({nextwt+wt,x_,y_});
                    }
                }
            }
        }
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        dijstra(grid,result);

        return result[m-1][n-1];
    }
};
