class Solution {
public:
    void fill(int x,int y,int m,int n,vector<vector<int>>& matrix){
        // right 
        for(int i = y+1;i<n;i++){
            if(matrix[x][i] == 0 || matrix[x][i] == 1){
                matrix[x][i] = 1;
            }
            else break;
        }
        // left
        for(int i = y-1;i>=0;i--){
            if(matrix[x][i] == 0 || matrix[x][i] == 1){
                matrix[x][i] = 1;
            }
            else break;
        }
        // down
        for(int i = x+1;i<m;i++){
            if(matrix[i][y] == 0 || matrix[i][y] == 1){
                matrix[i][y] = 1;
            }
            else break;
        }
        //up
        for(int i = x-1;i>=0;i--){
            if(matrix[i][y] == 0 || matrix[i][y] == 1){
                matrix[i][y] = 1;
            }
            else break;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int>(n,0));


        for(auto& v:guards){
            int a = v[0];
            int b = v[1];
            matrix[a][b] = 2;
        }
        for(auto& v: walls){
            int a = v[0];
            int b = v[1];
            matrix[a][b] = 3;
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 2){
                    fill(i,j,m,n,matrix);
                }
            }
        }
        int result =0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    result++;
                }
            }
        }
        return result;
    }
};
