class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(),points.end());

        int i = 1;
        int count = 0;

        vector<int> L = points[0];

        while(i < n){
            int cs = points[i][0];
            int ce = points[i][1];

            if(L[1] < cs){
                L = points[i];
                i++;
            }
            else if(L[1] <= ce){
                i++;
                count++;
            }
            else if(L[1] > ce){
                L = points[i];
                i++;
                count++;
            }
        }

        return n - count;
    }
};
