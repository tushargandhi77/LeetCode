class Solution {
public:
    bool traversal(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        unordered_set<int> st;

        for(int i = sr;i<=er;i++){
            for(int j = sc;j<=ec;j++){
                if(board[i][j] == '.') continue;

                if(st.find(board[i][j]) != st.end()) return false;

                st.insert(board[i][j]);
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0;row<9;row++){
            unordered_set<int> st;
            for(int col = 0;col<9;col++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()) return false;

                st.insert(board[row][col]);
            }
        }

        for(int col = 0;col<9;col++){
            unordered_set<int> st;
            for(int row = 0;row<9;row++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()) return false;

                st.insert(board[row][col]);
            }
        }

        for(int sr = 0;sr<9;sr+=3){
            int er = sr+2;
            for(int sc = 0;sc<9;sc+=3){
                int ec = sc+2;

                if(traversal(board,sr,er,sc,ec) == false) return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;

                string a = to_string(i) + "_ROW_" + to_string(board[i][j]);
                string b = to_string(j) + "_COL_" + to_string(board[i][j]);
                string c = to_string(i/3) + "_MIX_" + to_string(j/3) + "_MIX_" + to_string(board[i][j]);

                if(st.count(a) || st.count(b) || st.count(c)) return false;

                st.insert(a);
                st.insert(b);
                st.insert(c);
            }
        }

        return true;
    }
};
