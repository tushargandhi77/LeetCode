class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int maxArea = 0;

        for(auto dim: dimensions){
            int diag = dim[0]*dim[0] + dim[1]*dim[1];

            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = dim[0]*dim[1];
            }
            if(diag == maxDiag && dim[1]*dim[0] > maxArea){
                maxArea = dim[1]*dim[0];
            }
        }

        return maxArea;
    }
};
