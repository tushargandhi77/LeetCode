class Solution {
public:
    vector<vector<int>> dir{{0,-1},{0,1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& height) {
        int m = height.size();
        int n = height[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int row = 0;row<m;row++){
            for(const int col: {0,n-1}){
                pq.push({height[row][col],row,col});
                visited[row][col] = true;
            }
        }

        for(int col = 0;col<n;col++){
            for(const int row: {0,m-1}){
                pq.push({height[row][col],row,col});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int ht = it[0];
            int x = it[1];
            int y = it[2];

            for(auto& d : dir)
            {
                int x_ = x + d[0];
                int y_ = y + d[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && visited[x_][y_] == false)
                {
                    water += max((ht - height[x_][y_]),0);
                    int newht = max(ht,height[x_][y_]);
                    pq.push({newht,x_,y_});

                    visited[x_][y_] = true;
                }
            }
        }
        return water;
    }
};
