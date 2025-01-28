class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void BFS(int i,int j,vector<vector<int>>& grid,int& val){
        queue<pair<int,int>> que;
        que.push({i,j});

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            int x = it.first;
            int y = it.second;

            val += grid[x][y];
            grid[x][y] = 0;

            for(auto& dir: directions){
                int x_ = dir[0] + x;
                int y_ = dir[1] + y;

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] != 0){
                    que.push({x_,y_});
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();



        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] != 0){
                    int val = 0;
                    BFS(i,j,grid,val);
                    result = max(result,val);
                }
            }
        }       
        return result;
    }
};
