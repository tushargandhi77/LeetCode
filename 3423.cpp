class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            result = max(result,abs(nums[i] - nums[i-1]));
        }

        result = max(result,abs(nums[0]-nums[n-1]));
        return result;
    }
};
