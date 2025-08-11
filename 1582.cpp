// Brute Force

class Solution {
public:
    int m,n;

    bool isvalid(int x,int y,vector<vector<int>>& mat){
        for(int i = 0;i<m;i++){
            if(i == x) continue;

            if(mat[i][y] == 1) return false; 
        }

        for(int j = 0;j<n;j++){
            if(j == y) continue;

            if(mat[x][j] == 1) return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        int result = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 1 && isvalid(i,j,mat)){
                    result ++;
                }
            }
        }

        return result;
    }
};
