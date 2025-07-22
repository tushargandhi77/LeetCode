// DFS
class Solution {
public:

    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(int i,int j,vector<vector<char>>& grid){
        grid[i][j] = '0';

        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < grid.size() && j_ >= 0 && j_ < grid[0].size() && grid[i_][j_] == '1'){
                DFS(i_,j_,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    DFS(i,j,grid);
                    result++;
                }
            }
        }

        return result;
    }
};

// BFS
class Solution {
public:

    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void BFS(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> que;
        que.push({i,j});
        grid[i][j] = '0';

        while(!que.empty()){
            int u = que.front().first;
            int v = que.front().second;
            que.pop();

            for(auto& dir: directions){
                int i_ = dir[0] + u;
                int j_ = dir[1] + v;

                if(i_ >= 0 && j_ >= 0 && i_ < grid.size() && j_ < grid[0].size() && grid[i_][j_] == '1'){
                    que.push({i_,j_});
                    grid[i_][j_] = '0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    BFS(i,j,grid);
                    result++;
                }
            }
        }

        return result;
    }
};
