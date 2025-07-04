class Solution {
public:
    int m,n;
    int apples[55][55];
    int M = 1e9 + 7;
    int t[55][55][11];

    int solve(int i,int j,int k){
        if(apples[i][j] < k) return 0;

        if(k == 1){
            if(apples[i][j] >= 1) return 1;

            return 0;
        }

        if(t[i][j][k] != -1) return t[i][j][k];

        int answer = 0;

        // horizontal
        for(int h = i+1;h<m;h++){
            int lower_slice = apples[h][j];
            int upper_slice = apples[i][j] - lower_slice;

            if(upper_slice >= 1 && lower_slice >= k-1){
                answer = (answer + solve(h,j,k-1)%M)%M;
            }
        }

        // vertical
        for(int v = j+1;v<n;v++){
            
            int right_slice = apples[i][v];
            int left_slice = apples[i][j] - right_slice;

            if(left_slice >= 1 && right_slice >= k-1){
                answer = (answer + solve(i,v,k-1)%M) % M;
            }
        }

        return t[i][j][k] = answer;
    }
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        memset(apples,0,sizeof(apples));
        memset(t,-1,sizeof(t));

        // make apples array
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                apples[i][j] = apples[i][j+1];

                for(int l = i;l<m;l++){
                    if(pizza[l][j] == 'A'){
                        apples[i][j] += 1;
                    }
                }
            }
        }

        return solve(0,0,k);
    }
};
