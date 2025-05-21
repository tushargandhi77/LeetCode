class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isrowimpacted = false;
        bool iscolimpacted = false;

        for(int col = 0;col<n;col++){
            if(matrix[0][col] == 0){
                isrowimpacted = true;
                break;
            }
        }
        for(int row = 0;row<m;row++){
            if(matrix[row][0] == 0){
                iscolimpacted = true;
                break;
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(isrowimpacted){
            for(int i = 0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        if(iscolimpacted){
            for(int i = 0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
