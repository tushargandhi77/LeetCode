class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int sq = INT_MIN;

        vector<vector<int>> t(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 || j == 0){
                    t[i][j] = (matrix[i][j] == '0' ? 0 : 1);
                }
                else if(matrix[i][j] == '1'){
                    t[i][j] = 1 + min({t[i-1][j],t[i-1][j-1],t[i][j-1]});
                }
                sq = max(sq,t[i][j]);
            }
        }
        return sq*sq;
    }
};
