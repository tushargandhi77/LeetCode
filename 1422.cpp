class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zerosum(n);
        vector<int> onesum(n);

        zerosum[0] = s[0] == '0' ? 1 : 0;
        onesum[n-1] = s[n-1] == '1' ? 1 : 0;

        for(int i = 1;i<n;i++){
            zerosum[i] = zerosum[i-1] + (s[i] == '0' ? 1 : 0);
        }
        for(int i = n-2;i>=0;i--){
            onesum[i] = onesum[i+1] + (s[i] == '1' ? 1 : 0);
        } 

        int result = INT_MIN;
        for(int i = 0;i<n-1;i++){
            result = max(result,zerosum[i]+onesum[i+1]);
        }

        return result;

    }
};
