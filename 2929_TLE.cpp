class Solution {
public:
    int limit;
    int t[100006][3];
    long long solve(int countchild,int n){
        if(countchild == 3){
            if(n == 0) return 1;
            else return 0;
        }

        if(t[n][countchild] != -1) return t[n][countchild];

        long long ways = 0LL;

        for(int i = 0;i<=min(n,limit);i++){
            ways += solve(countchild+1,n-i);
        }

        return t[n][countchild] = ways;
    }
    long long distributeCandies(int n, int l) {
        limit = l;
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};
