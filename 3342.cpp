class Solution {
public:
    vector<vector<int>> directions{{0,-1},{0,1},{1,0},{-1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        result[0][0] = 0;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();

            int currtime = vec[0];
            int i = vec[1];
            int j = vec[2];

            if( i == m-1 && j == n-1) return currtime;

            for(auto& dir: directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n){
                    int step = (i_ + j_) % 2 == 0 ? 2 : 1;
                    int wait = max(moveTime[i_][j_] - currtime,0);
                    int arrtime = currtime + wait + step;
                    if(arrtime < result[i_][j_]){
                        result[i_][j_] = arrtime;
                        pq.push({arrtime,i_,j_});
                    }
                }
            }
        }
        return -1;
    }
};
