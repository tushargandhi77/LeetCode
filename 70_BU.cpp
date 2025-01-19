class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        vector<int> t(n+1,0);

        t[0] = 0;
        t[1] = 1;
        t[2] = 2;

        for(int i = 3;i<=3;i++){
            t[i] = t[i-2] + t[i-1];
        }
        
        return t[n];
    }
};
