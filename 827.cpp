// Method 1 Optimul
class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(int i,int j,vector<vector<int>>& grid,int ids){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1){
            return 0;
        }

        grid[i][j] = ids;

        int answer = 1;
        for(auto& dir: directions){
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;

            answer += DFS(i_,j_,grid,ids);
        }

        return answer;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ids = 2;
        unordered_map<int,int> mp;

        int max_answer = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    int size = DFS(i,j,grid,ids);
                    mp[ids] = size;
                    max_answer = max(max_answer,size);
                    ids++;
                }
            }
        }

        

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                unordered_set<int> sized;
                if(grid[i][j] == 0){
                    for(auto& dir: directions){
                        int i_ = dir[0] + i;
                        int j_ = dir[1] + j;

                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n){
                            sized.insert(grid[i_][j_]);
                        }
                    }
                    int group = 1;
                    for(int v: sized){
                        group += mp[v];
                    }

                    max_answer = max(max_answer,group);
                }
            }
        }
        return max_answer;
    }
};

// Method 2 
// TLE

class Solution {
public:
    int m,n;

    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]){
            return 0;
        }

        int answer = 1;
        visited[r][c] = true;

        for(auto& dir: directions){
            int r_ = r + dir[0];
            int c_ = c + dir[1];

            answer +=  DFS(r_,c_,grid,visited);
        }

        return answer;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();


        int max_ans = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0){
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    grid[i][j] = 1;

                    max_ans = max(DFS(i,j,grid,visited),max_ans);
                    grid[i][j] = 0;
                }
            }
        }


        return max_ans == INT_MIN ? m * n : max_ans;
    }
};
