class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> t(k,vector<int>(n,1));
        int result = 1;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                int mod = (nums[i]+nums[j])%k;

                t[mod][i] = max(t[mod][i],t[mod][j]+1);

                result = max(result,t[mod][i]);
            }
        }

        return result;
    }
};
