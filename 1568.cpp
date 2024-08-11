class Solution {
public:
    int m,n;
    void DFS(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j] == 0){
            return;
        }
        vis[i][j] = true;

        DFS(grid,i+1,j,vis);
        DFS(grid,i-1,j,vis);
        DFS(grid,i,j+1,vis);
        DFS(grid,i,j-1,vis);
    }
    int numberofisland(vector<vector<int>>& grid){
        int island = 0;
        vector<vector<bool>> vis(m,vector<bool>(n));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    DFS(grid,i,j,vis);
                    island++;
                }
            }
        }
        return island;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int island = numberofisland(grid);
        if(island > 1 || island == 0){
            return 0;
        }
        else{
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;

                        island = numberofisland(grid);
                        if(island > 1 || island == 0){
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};
