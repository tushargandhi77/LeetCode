class Solution {
public:
    
    bool isvalid(vector<vector<char>>& board,int row,int col,char ch){
        for(int i = 0;i<9;i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
        } 

        int start_i = (row/3) * 3;
        int start_j = (col/3) * 3;

        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[i+start_i][j+start_j] == ch) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){

                if(board[i][j] == '.'){

                    for(char ch = '1'; ch <= '9';ch++){

                        if(isvalid(board,i,j,ch)){
                            board[i][j] = ch;

                            if(solve(board) == true) return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }

            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
