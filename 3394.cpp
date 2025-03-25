class Solution {
public:
    int merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals),end(intervals));

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1;i<n;i++){
            if(result.back()[1] > intervals[i][0]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        return result.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> X;
        vector<vector<int>> Y;

        for(auto& rect: rectangles){
            int x1 = rect[0];
            int x2 = rect[2];
            X.push_back({x1,x2});
            int y1 = rect[1];
            int y2 = rect[3];
            Y.push_back({y1,y2});
        }

        int x_cal = merge(X);

        int y_cal = merge(Y);

        return max(x_cal,y_cal) >= 3;
    }
};
