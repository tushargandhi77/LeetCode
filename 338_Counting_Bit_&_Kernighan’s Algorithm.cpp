class Solution {
public:
    // Brian Kernighan’s Algorithm (Efficient)
    int countOnes(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // Removes the last set bit
        count++;
    }
    return count;
    }
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);

        for(int i = 0;i<=n;i++){
            // result[i] = __builtin_popcount(i);
            result[i] = countOnes(i);
        }
        return result;
    }
};
