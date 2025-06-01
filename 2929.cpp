class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0LL;

        int minL = max(n-2*limit,0);
        int maxL = min(n,limit);

        for(int i = minL;i<=maxL;i++){
            int  N = n - i;
            int minch2 = max(N-limit,0);
            int maxch2 = min(limit,N);

            ways += (long long)(maxch2-minch2+1);
        }
        return ways;
    }
};
