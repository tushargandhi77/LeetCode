class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int a = 0;
        int b = 1;
        int ans;
        for(int i = 2;i<=n;i++){
            ans = a + b;
            a = b;
            b = ans;
        }

        return ans;
    }
};
