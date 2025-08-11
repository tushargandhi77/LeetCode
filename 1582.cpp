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

// Better

class Solution {
public:
    int m,n;

    void Build(vector<int>& rowSum,vector<int>& colSum,vector<vector<int>>& mat){
        for(int i = 0;i<m;i++){
            int sum = 0;
            for(int j = 0;j<n;j++){
                sum += mat[i][j];
            }
            rowSum[i] = sum;
        }

        for(int j = 0;j<n;j++){
            int sum = 0;
            for(int i = 0;i<m;i++){
                sum += mat[i][j];
            }
            colSum[j] = sum;
        }

    }
    int numSpecial(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        vector<int> rowSum(m,0);
        vector<int> colSum(n,0);

        Build(rowSum,colSum,mat);

        int result = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 1 && rowSum[i] < 2 && colSum[j] < 2){
                    result++;
                }
            }
        }

        return result;
    }
};
