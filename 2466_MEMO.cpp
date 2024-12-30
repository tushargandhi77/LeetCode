class Solution {
public:
    int Z,O;
    int L,H;
    const int mod = 1e9+7;
    int t[100001];
    int solve(int count){
        if(count>H) return 0;

        bool addOne = false;

        if(t[count]!=-1) return t[count];
        if(count>=L){
            addOne = true;
        }

        int take_zero = solve(count+Z)%mod;
        int take_one = solve(count+O)%mod;

        return t[count] = (take_zero + take_one + addOne)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        Z = zero;
        O = one;
        L = low;
        H = high;
        memset(t,-1,sizeof(t));
        return solve(0);
    }
};
