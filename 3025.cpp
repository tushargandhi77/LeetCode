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


// M2

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        sort(begin(points),end(points),[](vector<int>& point1,vector<int>& point2){
            if(point1[0] == point2[0]){
                return point1[1] > point2[1];
            }

            return point1[0] < point2[0];
        });

        for(int i = 0;i<n;i++){
            // let this is upper point 
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;

            // let this is lower points
            for(int j = i+1;j<n;j++){
                

                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(y2 > y1) continue;

                if(y2 > maxY){
                    result++;
                    maxY = y2;
                }
            }
        }

        return result;
    }
};
