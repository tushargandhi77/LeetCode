class Solution {
public:
    long t[301][302];
    const int MOD = 1e9+7;

    long long intpow(int base,int x,int n){
        long long result = 1;

        for(int i = 0;i<x;i++){
            result *= base;
            if(result > n) return n+1;
        }
        
        return result;
    }

    int solve(int idx,int currnum,int n,int x){
        if(currnum == n) return 1;

        if(idx > n) return 0;

        if(currnum > n) return 0;

        if(t[idx][currnum] != -1) return t[idx][currnum];

        long long result = 0;

        for(int i = idx;i<=n;i++){
            long long p = intpow(i,x,n);

            if(currnum+p > n) break;

            result = (result + solve(i+1,currnum+p,n,x))%MOD;
        }

        return t[idx][currnum] = result%MOD;
    }
    int numberOfWays(int n, int x) {
        memset(t,-1,sizeof(t));
        return solve(1,0,n,x);
    }
};
