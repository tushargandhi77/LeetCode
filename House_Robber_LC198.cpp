class Solution {
public:
    int dp[101];
    int solve(int idx,vector<int>& nums){
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = solve(idx+2,nums) + nums[idx];
        int not_take = solve(idx+1,nums);

        return dp[idx] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
