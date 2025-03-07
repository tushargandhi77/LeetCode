class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals),end(intervals));

        int i = 0;
        int j = 1;
        int count = 0;

        while(j < n){

            int cs = intervals[i][0];
            int ce = intervals[i][1];

            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if(ce <= ns){
                i = j;
                j++;
            }
            else if(ce <= ne){
                j++;
                count++;
            }
            else if(ce > ne){
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};
