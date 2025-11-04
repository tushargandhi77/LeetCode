class Solution {
public:
    int t[201][1002];
    int solve(int idx,int target,vector<int>& nums){
        if(target == 0) return 1;

        if(target < 0) return 0;

        if(idx >= nums.size()) return 0;

        if(t[idx][target+1] != -1) return t[idx][target+1];

        int take = solve(0,max(-1,target-nums[idx]),nums);
        int not_take = solve(idx+1,target,nums);

        return t[idx][target+1] = take + not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(0,target,nums);
    }
};
