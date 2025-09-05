// M1
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 1;

        while(true){
            long long val = (long long)num1 - t*(long long)num2;

            if(val < 0) return -1;

            if(__builtin_popcountll(val) <= t && t <= val){
                return t;
            }
            t++;
        }

        return -1;
    }
};
