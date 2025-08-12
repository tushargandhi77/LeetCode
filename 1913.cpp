class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();

        int maxD = nums[n-2] * nums[n-1];
        int minD = nums[0] * nums[1];

        return maxD - minD;
    }
};
