class Solution {
public:
    int result;
    int nonobs;
    int m,n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    void solve(int i,int j,int count,vector<vector<int>>& grid){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return;

        if(grid[i][j] == 2){
            if(count == nonobs) result++;
            return;
        }

        grid[i][j] = -1;
        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            solve(i_,j_,count+1,grid);
        }
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int sr,sc;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0){
                    nonobs++;
                }
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                    nonobs++;
                }
            }
        }

        solve(sr,sc,0,grid);
        return result;
    }
};
