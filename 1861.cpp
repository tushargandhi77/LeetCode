class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // transpose + row reverse

        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n,vector<char>(m));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                result[j][i] = box[i][j];
            }
        }
        for(auto &vec: result){
            reverse(begin(vec),end(vec));
        }

        // gravity 
        int row = result.size();
        int col = result[0].size();

        for(int j = 0;j<col;j++){
            for(int i = row-1;i>=0;i--){
                if(result[i][j] == '.'){
                    int stoneRow = -1;
                    for(int k = i-1;k>=0;k--){
                        if(result[k][j] == '*'){
                            break;
                        }
                        else if(result[k][j] == '#'){
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow != -1){
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }
        return result;
    }
};
