class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int M = 1e9+7;
    int t[51][51][51];
    int solve(int i,int j,int m,int n,int move){
        if(move < 0) return 0;

        if(i < 0 || i >= m || j < 0 || j >= n) return 1;

        if(t[i][j][move] != -1) return t[i][j][move];

        int result = 0;
        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            result = (result%M + solve(i_,j_,m,n,move-1)%M)%M;
        }

        return t[i][j][move] = result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,m,n,maxMove);
    }
};

class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    const int MOD = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        int t[50][50][52];
        memset(t,0,sizeof(t));

        for(int k = 1;k<=maxMove;k++){
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    for(auto& dir: directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n){
                            t[i][j][k] = (1 + t[i][j][k])%MOD;
                        }
                        else{
                            t[i][j][k] = (t[i][j][k]%MOD + t[i_][j_][k-1]%MOD)%MOD;
                        }
                    }
                }
            }
        }

        return t[startRow][startCol][maxMove];
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> t(50,vector<int>(50));
        t[startRow][startColumn] = 1;
        int result = 0;

        for(int k = 1;k<=maxMove;k++){
            vector<vector<int>> temp(50,vector<int>(50));
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    for(auto& dir: directions){
                        int x = i + dir[0];
                        int y = j + dir[1];

                        if(x < 0 || x >= m || y < 0 ||  y>= n){
                            result = (result + t[i][j])%MOD;
                        }
                        else{
                            temp[x][y] = (temp[x][y] + t[i][j])%MOD;
                        }
                    }
                }
            }
            t = temp;
        }

        return result;
    }
};
