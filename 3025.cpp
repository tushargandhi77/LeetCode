// M1 
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for(int i = 0;i<n;i++){
            // let this is upper point 
            int x1 = points[i][0];
            int y1 = points[i][1];

            // let this is lower points
            for(int j = 0;j<n;j++){
                if(i == j) continue;

                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x2 >= x1 && y1 >= y2){
                    bool haspointinside = false;
                    for(int k = 0;k<n;k++){
                        if(i == k || j == k) continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if((x3 >= x1 && x3 <= x2 && y3 >= y2 && y3 <= y1)){
                            haspointinside = true;
                            break;
                        }
                    }

                    if(!haspointinside) result++;
                }
            }
        }

        return result;
    }
};
