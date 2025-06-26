// Bottom Up

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> t(n,vector<int>(n));

        for(int col = 0;col<n;col++){
            t[0][col] = matrix[0][col];
        }

        for(int row = 1;row<n;row++){
            for(int col = 0;col<n;col++){
                t[row][col] = matrix[row][col] + min({t[row-1][col],t[row-1][max(0,col-1)],t[row-1][min(n-1,col+1)]});
            }
        }

        return *min_element(t[n-1].begin(),t[n-1].end());
    }
};


// REcusion + Memo
class Solution {
public:
    int n;
    int t[101][101];
    int solve(int row,int col,vector<vector<int>>& matrix){
        if(row == n-1){
            return matrix[row][col];
        }

        if(t[row][col] != -1) return t[row][col];

        int min_sum = INT_MAX;
        int sum = matrix[row][col];

        if(row + 1 < n){
            min_sum = min(min_sum,sum + solve(row+1,col,matrix));
        }

        if(row+1 < n && col-1 >= 0){
            min_sum = min(min_sum,sum + solve(row+1,col-1,matrix));
        }

        if(row+1 < n && col + 1 < n){
            min_sum = min(min_sum,sum + solve(row+1,col+1,matrix));
        }

        return t[row][col] = min_sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        n = matrix.size();

        memset(t,-1,sizeof(t));

        for(int col = 0;col<n;col++){
            result = min(result,solve(0,col,matrix));
        }

        return result;
        
    }
};
