class Solution {
public:
    int t[2501][2501];
    int solve(int idx,int prev,vector<int>& nums){
        if(idx >= nums.size()) return 0;

        if(t[idx][prev+1] != -1) return t[idx][prev+1];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
            take = 1 + solve(idx+1,idx,nums);
        }       

        int skip = solve(idx+1,prev,nums);

        return t[idx][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};
