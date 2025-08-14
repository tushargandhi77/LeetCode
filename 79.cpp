class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool isfind(int i,int j,int idx,vector<vector<char>>& board, string& word){
        if(idx == word.length()) return true;

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for(auto& dir: directions){
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;

            if(isfind(i_,j_,idx+1,board,word) == true) return true;
        }

        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0] && isfind(i,j,0,board,word))return true;
            }
        }

        return false;
    }
};
