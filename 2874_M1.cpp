class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        int maxDiff = 0;
        int maxi = 0;

        for(int k = 0;k<n;k++){
            result = max(result,(long long)maxDiff*nums[k]);
            maxDiff = max(maxDiff,maxi - nums[k]);
            maxi = max(maxi,nums[k]);
        }
        return result;
    }
};
