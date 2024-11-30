class Solution {

public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n = matrix[0].size();

        int maxRow = 0;

        for(auto& currRow: matrix){
            vector<int> inverted(n);

            for(int i = 0;i<n;i++){
                inverted[i] = 1 - currRow[i];
            }

            int count= 0;

            for(auto& row: matrix){
                if(row == currRow || row == inverted){
                    count++;
                }
            }
            maxRow = max(count,maxRow);
        }
        return maxRow;
    }
};
