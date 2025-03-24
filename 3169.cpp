class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int start = 0;
        int end = 0;
        sort(meetings.begin(),meetings.end());
        int result = 0;
        for(int i = 0;i<meetings.size();i++){
            if(meetings[i][0] > end){
                result += (meetings[i][0]-end-1);
            }
            end = max(end,meetings[i][1]);
        }

        if(days > end){
            result += (days - end);
        }

        return result;
    }
};
