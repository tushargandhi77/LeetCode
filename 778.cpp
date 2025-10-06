// DFS

class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    bool possibleInDFS(int i,int j,int time,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || visited[i][j] == true || grid[i][j] > time){
            return false;
        }

        visited[i][j] = true;

        if(i == grid.size()-1 && j == grid.size()-1){
            return true;
        }


        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(possibleInDFS(i_,j_,time,grid,visited)) return true;
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = n*n - 1;
        int result = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            vector<vector<bool>> visited(n,vector<bool>(n,false));
            if(possibleInDFS(0,0,mid,grid,visited)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
};

// BFS

class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    bool possibleInBFS(int i,int j,int time,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        queue<pair<int,int>> que;
        que.push({i,j});
        visited[i][j] = true;
        int n = grid.size();

        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            if(x == n-1 && y == n-1) return true;

            for(auto& dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < n && y_ >= 0  && y_ < n && visited[x_][y_]==false && grid[x_][y_] <= time){
                    que.push({x_,y_});
                    visited[x_][y_] = true;
                }
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = n*n - 1;
        int result = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            vector<vector<bool>> visited(n,vector<bool>(n,false));
            if(possibleInBFS(0,0,mid,grid,visited)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
};
