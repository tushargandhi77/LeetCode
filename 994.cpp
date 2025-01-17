class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshorange = 0;
        queue<pair<int,int>> que;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshorange++;
                }
            }
        }

        if(freshorange == 0) return 0;

        int minutes = 0;

        while(!que.empty()){
            int N = que.size();
            while(N--){
                auto it = que.front();
                que.pop();

                int x = it.first;
                int y = it.second;

                for(auto& dir : directions){
                    int x_ = dir[0] + x;
                    int y_ = dir[1] + y;

                    if(x_ >= 0 && y_ >=0 && x_ < m && y_ < n && grid[x_][y_] == 1){
                        que.push({x_,y_});
                        grid[x_][y_] = 2;
                        freshorange--;
                    }
                }
            }
            minutes++;
        }
    
        return freshorange == 0 ? minutes -1 : -1;
    }
};
