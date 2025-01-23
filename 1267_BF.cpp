class Solution {
public:
    int m,n;
    bool checkcomm(vector<vector<int>>& grid,int row,int col){
        bool r = false;

        for(int i = row+1;i<m;i++){
            if(grid[i][col] == 1){
                r = true;
                break;
            }
        }
        for(int i = row-1;i>=0;i--){
            if(grid[i][col] == 1){
                r = true;
                break;
            }
        }
        bool c = false;
        for(int i = col+1;i<n;i++){
            if(grid[row][i] == 1){
                c = true;
                break;
            }
        }
        for(int i = col-1;i>=0;i--){
            if(grid[row][i] == 1){
                c = true;
                break;
            }
        }
        return r | c;
    }
    int countServers(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && checkcomm(grid,i,j)){
                    result++;
                }
            }
        }

        return result;
    }
};
