
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> que;

        que.push({0,{0,0}});
        result[0][0] = 0;

        while(!que.empty()){
            auto it = que.top();
            que.pop();

            int dist  = it.first;
            int i = it.second.first;
            int j = it.second.second;

            for(auto & dir: directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(x >= 0 && x < m &&  y >= 0 && y < n){
                    int wt = grid[x][y];
                    if(dist + wt < result[x][y]){
                        result[x][y] = dist + wt;
                        que.push({dist+wt,{x,y}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
