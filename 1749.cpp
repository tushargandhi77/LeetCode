class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currmaxsum = nums[0];
        int currminsum = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i = 1;i<n;i++){
            currmaxsum = max(nums[i],currmaxsum+nums[i]);

            currminsum = min(nums[i],currminsum+nums[i]);

            maxsum = max(maxsum,currmaxsum);

            minsum = min(minsum,currminsum);
        }

        return max(maxsum,abs(minsum));
    }
};
