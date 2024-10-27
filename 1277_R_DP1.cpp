class Solution {
public:
    int m;
    int n;
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& t){
        if(i >= m || j >= n) return 0;

        if(matrix[i][j] == 0) return 0;

        if(t[i][j] != -1) return t[i][j];
        int right = solve(i,j+1,matrix,t);
        int left = solve(i+1,j,matrix,t);
        int bottom = solve(i+1,j+1,matrix,t);

        return t[i][j] = 1 + min({right,left,bottom});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0; j < n; j++){
                result += solve(i,j,matrix,t);
            }
        }   
        return result;   
    }
};
