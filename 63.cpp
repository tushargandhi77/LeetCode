// Method 1 :-> Recusion

class Solution {
public:
    int m,n;

    int solve(int i,int j,vector<vector<int>>& Grid){
        if(i < 0 || i >= m || j < 0 || j >= n || Grid[i][j] == 1){
            return 0;
        }
        
        if(i == m-1 && j == n-1){
            return 1;
        }

        int right = solve(i,j+1,Grid);
        int down = solve(i+1,j,Grid);

        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        m = Grid.size();
        n = Grid[0].size();
        return solve(0,0,Grid);
    }
};

// Method 2 :-> Memoization

class Solution {
public:
    int m,n;
    int t[101][101];
    int solve(int i,int j,vector<vector<int>>& Grid){
        if(i < 0 || i >= m || j < 0 || j >= n || Grid[i][j] == 1){
            return 0;
        }
        
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i,j+1,Grid);
        int down = solve(i+1,j,Grid);

        return t[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        m = Grid.size();
        n = Grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,Grid);
    }
};

// Method 3 :-> Botom Up

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();

        vector<vector<int>> t(m,vector<int>(n));

        for(int col = 0;col<n;col++){

            if(Grid[0][col] == 1){
                t[0][col] = 0;
            }
            else if(col > 0 && Grid[0][col-1] == 1){
                t[0][col] = 0;
                Grid[0][col] = 1;
            }
            else{
                t[0][col] = 1;
            }
        }

        for(int row = 0;row<m;row++){
            if(Grid[row][0] == 1){
                t[row][0] = 0;
            }
            else if(row > 0 && Grid[row-1][0] == 1){
                t[row][0] = 0;
                Grid[row][0] = 1;
            }
            else{
                t[row][0] = 1;
            }
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(Grid[i][j] == 1){
                    t[i][j] = 0;
                }
                else{
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }

        return t[m-1][n-1];
    }
};
