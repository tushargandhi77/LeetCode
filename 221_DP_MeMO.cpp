class Solution {
public:
    int m;
    int n;
    int solve(int i,int j,vector<vector<char>>& matrix,vector<vector<int>> &t){
        if(i >= m || j >= n) return 0;
        if(matrix[i][j] == '0') return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i+1,j,matrix,t);
        int diag = solve(i+1,j+1,matrix,t);
        int bottom = solve(i,j+1,matrix,t);

        return t[i][j] = 1 + min({right,diag,bottom});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        int sq = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                sq = max(sq,solve(i,j,matrix,t));
            }
        }
        return sq*sq;
    }
};
