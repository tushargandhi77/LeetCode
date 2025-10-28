class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1,vector<int>(k+1,0));

        for(int j = 0;j<=n;j++){
            t[j][0] = 1;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=k;j++){
                int result = 0;
                for(int inv = 0;inv<=min(i-1,j);inv++){
                    result = result%M + t[i-1][j-inv]%M;
                }
                t[i][j] = result%M;
            }
        }

        return t[n][k];
    }
};

class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1,vector<int>(k+1));

        for(int i = 0;i<=n;i++){
            t[i][0] = 1;
        }

        for(int i = 1;i<=n;i++){
            long long cumsum = 1;
            for(int j = 1;j<=k;j++){
                cumsum += t[i-1][j];

                if(j >= i){
                    cumsum -= t[i-1][j-i];
                }
                t[i][j] = cumsum%M;


            }
        }

        return t[n][k];
    }
};

class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1,vector<int>(k+1));

        for(int i = 0;i<=n;i++){
            t[i][0] = 1;
        }

        for(int i = 1;i<=n;i++){
            long long cumsum = 1;
            for(int j = 1;j<=k;j++){
                cumsum += t[i-1][j];

                if(j >= i){
                    cumsum -= t[i-1][j-i];
                }
                t[i][j] = cumsum%M;


            }
        }

        return t[n][k];
    }
};

