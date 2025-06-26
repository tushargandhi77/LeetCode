class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        int powerval = 1; // 2 ^ 0

        int n = s.length();

        for(int i = n-1;i>=0;i--){
            if(s[i] == '0'){
                length++;
            }
            else if(powerval <= k){
                k -= powerval;
                length++;
            }

            if(powerval <= k){
                powerval = 2 * powerval; // left shift powerval << 1;
            }
        }

        return length;
    }
};
