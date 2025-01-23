class Solution {
public:
    int t[101];
    int solve(int idx,int n,vector<int>& nums){
        if(idx >= n){
            return 0;
        }
        if(t[idx] != -1) return t[idx];

        int take_one = solve(idx+2,n,nums) + nums[idx];
        int not_take = solve(idx+1,n,nums);

        return t[idx] = max(take_one,not_take);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        memset(t,-1,sizeof(t));
        int rob1 = solve(0,nums.size()-1,nums);
        memset(t,-1,sizeof(t));
        int rob2 = solve(1,nums.size(),nums);
        return max(rob1,rob2);
    }
};
