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

// DSU
class DSU{
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    DSU(int n): count(0){
        parent.resize(n);
        rank.resize(n);


        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent;;
            rank[x_parent]++;
        } 
        count--;
    }

    void addisand(){
        count++;
    }

    int answer(){
        return count;
    }

};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m*n);


        vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    dsu.addisand();
                    int idx = i * n + j;
                    for(auto& dir: directions){
                        int i_ = dir[0] + i;
                        int j_ = dir[1] + j;

                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == '1'){
                            int idx_ = i_ * n + j_;
                            dsu.Union(idx,idx_);
                        }
                    }
                }
            }
        }

        return dsu.answer();
    }
};
