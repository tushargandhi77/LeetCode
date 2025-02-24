class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = (a | b) ^ c;
        int double_flip = (a&b) & flip;
        return __builtin_popcount(flip) + __builtin_popcount(double_flip);
    }
};
