


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
