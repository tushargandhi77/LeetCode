class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals),end(intervals));

        int i = 1;
        int count = 0;
        vector<int> L = intervals[0];

        while(i < n){
            int cs = intervals[i][0];
            int ce = intervals[i][1];

            if(L[1] <= cs){
                L = intervals[i];
                i++;
            }
            else if(L[1] <= ce){
                i++;
                count++;
            }
            else if(L[1] > ce){ 
                L = intervals[i];
                i++;
                count++;
            }
        }
        return count;
    }
};
