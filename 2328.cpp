class Solution {
public:
    int m,n;
    const int MOD = 1e9+7;

    int t[1001][1001];
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(int i,int j,vector<vector<int>>& grid){

        if(t[i][j] != -1) return t[i][j];

        int answer = 1;

        for(auto& dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] < grid[i][j]){
                answer = (answer + DFS(i_,j_,grid)%MOD)%MOD;
            }
        }

        return t[i][j] = answer;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));

        int result = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                result = (result + DFS(i,j,grid)%MOD)%MOD;
            }
        }

        return result;
    }
};
