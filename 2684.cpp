class Solution {
public:
    vector<vector<int>> directions{{-1,1},{0,1},{1,1}};
    int m;
    int n;
    int DFS(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& t){
        int moves = 0;
        if(t[row][col] != -1) return t[row][col];
        for(auto& dir:directions){
            int new_row = row+dir[0];
            int new_col = col+dir[1];

            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[row][col] < grid[new_row][new_col]){
                moves = max(moves,1 + DFS(new_row,new_col,grid,t));
            }
        }
        return t[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        vector<vector<int>> t(m,vector<int>(n,-1));
        for(int row = 0;row < m;row++){
            result = max(result,DFS(row,0,grid,t));
        }
        return result;
    }
};
