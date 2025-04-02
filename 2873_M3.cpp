class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        int maxDiff = 0;
        int maxi = 0;

        for(int i = 0;i<n;i++){
            result = max(result,(long long)maxDiff*nums[i]);
            maxDiff = max(maxDiff,maxi-nums[i]);
            maxi = max(maxi,nums[i]);
        }

        return result;
    }
};
