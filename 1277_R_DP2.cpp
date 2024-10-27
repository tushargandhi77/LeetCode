class Solution {
public:
    int m;
    int n;
    int t[301][301];
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i >= m || j >= n) return 0;

        if(matrix[i][j] == 0) return 0;

        if(t[i][j] != -1) return t[i][j];
        int right = solve(i,j+1,matrix);
        int left = solve(i+1,j,matrix);
        int bottom = solve(i+1,j+1,matrix);

        return t[i][j] = 1 + min({right,left,bottom});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(t,-1,sizeof(t));
        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0; j < n; j++){
                result += solve(i,j,matrix);
            }
        }   
        return result;   
    }
};
