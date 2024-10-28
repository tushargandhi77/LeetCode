class Solution {
public:
    vector<vector<int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,pair<int,int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x,int y){
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            int diff = pq.top().first;
            auto it = pq.top().second;

            int x = it.first;
            int y = it.second;

            pq.pop();

            if(x == m-1 && y == n-1) return diff;

            for(auto& dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_)){
                    int maxDiff = max(diff,abs(heights[x][y]-heights[x_][y_]));
                    if(maxDiff < result[x_][y_]){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff,{x_,y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
