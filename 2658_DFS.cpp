class Solution {
public:
    int m,n;
    void DFS(int i,int j,vector<vector<int>>& grid,int& val){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return;
        }

        val += grid[i][j];
        grid[i][j] = 0;

        DFS(i+1,j,grid,val);
        DFS(i-1,j,grid,val);
        DFS(i,j+1,grid,val);
        DFS(i,j-1,grid,val);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();



        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] != 0){
                    int val = 0;
                    DFS(i,j,grid,val);
                    result = max(result,val);
                }
            }
        }       
        return result;
    }
};
