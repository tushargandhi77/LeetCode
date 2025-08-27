class Solution {
public:
    vector<vector<int>> directions{{1,1},{1,-1},{-1,-1},{-1,1}};
    int m,n;

    int solve(int i,int j,vector<vector<int>>& grid,int d,bool canTurn,int val){
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val) return 0;

        int length = 0;

        int sameDir = 1 + solve(i_,j_,grid,d,canTurn,val == 2 ? 0 : 2);

        length = max(length,sameDir);

        if(canTurn == true){
            length = max(length,1 + solve(i_,j_,grid,(d+1)%4,false,val == 2 ? 0 : 2));
        }

        return length;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int d = 0;d<=3;d++){
                        result = max(result,solve(i,j,grid,d,true,2)+1);
                    }
                }
            }
        }

        return result;
    }
};
