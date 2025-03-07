class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(),points.end());

        int i = 0;
        int j = 1;
        int count = 0;

        while(j < n){
            int cs = points[i][0];
            int ce = points[i][1];

            int ns = points[j][0];
            int ne = points[j][1];

            if(ce < ns){
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

        return n - count;
    }
};
