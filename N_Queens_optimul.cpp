class Solution {
public:
    int N;
    vector<vector<string>> result;
    
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antidiags;

    void solve(vector<string>& board,int row){
        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0;col < N;col++){
            int diagsum = row+col;
            int antidiagsum = row-col;

            if(cols.find(col) != cols.end() || diags.find(diagsum) != diags.end() || antidiags.find(antidiagsum) != antidiags.end()){
                continue;
            }

            cols.insert(col);
            diags.insert(diagsum);
            antidiags.insert(antidiagsum);

            board[row][col] = 'Q';

            solve(board,row+1);

            cols.erase(col);
            diags.erase(diagsum);
            antidiags.erase(antidiagsum);

            board[row][col] = '.';
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        N = n;
        solve(board,0);

        return result;    
    }
};
