class Solution {
public:
    int t[10001];
    int solve(int n){
        if(n == 0) return 0;

        if(t[n] != -1) return t[n];

        int min_sq = INT_MAX;

        for(int i = 1;i*i<=n;i++){
            int result = 1 + solve(n-i*i);
            min_sq = min(result,min_sq);
        }

        return t[n] = min_sq;
    }
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};
