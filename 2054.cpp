class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int result = INT_MIN;

        int n = events.size();
        for(int i = 0;i<n;i++){
            int val = events[i][2];
            result = max(val,result);
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                if(events[j][1] >= events[i][0] && events[j][0] <= events[i][1]) continue;

                result = max(result,val+events[j][2]);
            }
        }
        return result;
    }
};
