class Solution {
public:
    int N;
    bool isvalid(vector<string>& board,int row,int col){
        // upward
        for(int i = row-1;i>=0;i--){
            if(board[i][col] == 'Q') return false;
        }

        // Diagleft
        for(int i = row-1,j = col-1;i>=0 && j >= 0 ; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        // DiagRight
        for(int i = row-1,j = col+1; i>=0 && j < N ; i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(vector<string>& board,int row,vector<vector<string>>& result){
        if(row >= N){
            result.push_back(board);
        }

        for(int col = 0;col<N;col++){

            if(isvalid(board,row,col)){
                board[row][col] = 'Q';

                solve(board,row+1,result);

                board[row][col] = '.';

            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n,string(n,'.'));

        vector<vector<string>> result;

        solve(board,0,result);

        return result;
    }
};
