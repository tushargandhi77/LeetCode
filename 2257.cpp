class Solution {
public:
    void fill(int x,int y,int m,int n,vector<vector<int>>& matrix){
        // right
        for(int j = y+1;j<n;j++){
            if(matrix[x][j] == 0 || matrix[x][j] == 1) matrix[x][j] = 1;
            else break;
        }

        // lleft
        for(int j = y-1;j>=0;j--){
            if(matrix[x][j] == 0 || matrix[x][j] == 1) matrix[x][j] = 1;
            else break;
        }

        // down 
        for(int i = x+1;i<m;i++){
            if(matrix[i][y] == 0 || matrix[i][y] == 1) matrix[i][y] = 1;
            else break;
        }

        // up
        for(int i = x-1;i>=0;i--){
            if(matrix[i][y] == 0 || matrix[i][y] == 1) matrix[i][y] = 1;
            else break;
        }

    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int>(n,0));

        for(auto& guard : guards){
            int x = guard[0];
            int y = guard[1];
            matrix[x][y] = 2;
        }
        for(auto& wall: walls){
            int x = wall[0];
            int y = wall[1];
            matrix[x][y] = 3;
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 2){
                    fill(i,j,m,n,matrix);
                }
            }
        }

        int result = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0) result++;
            }
        }

        return result;
    }
};
