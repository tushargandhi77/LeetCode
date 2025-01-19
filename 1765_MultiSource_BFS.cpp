class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> result(m,vector<int>(n,-1));

        vector<vector<int>> visited(m,vector<int>(n,false));
        queue<pair<int,int>> que;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j] == 1){
                    que.push({i,j});
                    visited[i][j] = true;
                    result[i][j] = 0;
                }
            }
        }

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            int x = it.first;
            int y = it.second;

            for(auto& dir: directions){
                int x_ = dir[0] + x;
                int y_ = dir[1] + y;

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && visited[x_][y_] == false){
                    visited[x_][y_] = true;
                    que.push({x_,y_});
                    result[x_][y_] = 1 + result[x][y];
                }
            }
        }
        return result;
    }
};
