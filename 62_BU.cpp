class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m,vector<int>(n,0));
        if(m == 1 && n == 1) return 1;

        // initial state
        t[0][0] = 0;

        for(int i = 1;i<n;i++){
            t[0][i] = 1;
        }
        for(int i = 1;i<m;i++){
            t[i][0] = 1;
        }


        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};
