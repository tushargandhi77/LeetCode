class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int result;
        if(n == 1){
            return nums[0];
        }

        int prev_prev = 0;
        int prev = nums[0];

        for(int i = 2;i<=n;i++){
            int skip = prev;
            int steal = nums[i-1] + prev_prev;

            result = max(skip,steal);

            prev_prev = prev;
            prev = result;
        }
        return result;
    }
};
