// Method 1:> MEMO


class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(t[i][j] != -1) return t[i][j];

        if(i == m-1){
            return t[i][j] = grid[i][j] + solve(i,j+1,grid);
        }

        if(j == n-1){
            return t[i][j] = grid[i][j] + solve(i+1,j,grid);
        }

        return t[i][j] = grid[i][j] + min(solve(i+1,j,grid),solve(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};


// Method 2 :-> Bottom Up

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m,vector<int>(n,INT_MAX));

        t[0][0] = grid[0][0];

        for(int i = 1;i<m;i++){
            t[i][0] = grid[i][0] + t[i-1][0];
        }

        for(int i = 1;i<n;i++){
            t[0][i] = grid[0][i] + t[0][i-1];
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                t[i][j] = grid[i][j] + min(t[i-1][j],t[i][j-1]);
            }
        }

        return t[m-1][n-1];
    }
};
