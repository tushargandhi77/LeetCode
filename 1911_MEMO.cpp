class Solution {
public:
    int n;
    long long t[100005][2];
    long long solve(int idx,bool iseven,vector<int>& nums){
        if(idx >= n) return 0;

        if(t[idx][iseven] != -1) return t[idx][iseven];

        long long skip = solve(idx+1,iseven,nums);

        long long val = nums[idx];

        if(!iseven){
            val = -val;
        }

        long long take = solve(idx+1,!iseven,nums) + val;

        return t[idx][iseven] = max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,true,nums);
    }
};
