class Solution {
public:
    int t[201][20001];
    bool solve(int idx,int x,vector<int>& nums){
        if(x == 0) return true;

        if(idx >= nums.size()) return false;

        if(t[idx][x] != -1) return t[idx][x];
        bool take = false;
        if(x >= nums[idx]){
            take = solve(idx+1,x - nums[idx],nums);
        }
        bool not_take = solve(idx+1,x,nums);

        return t[idx][x] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums),end(nums),0);

        if(sum % 2 != 0) return false;
        
        memset(t,-1,sizeof(t));
        return solve(0,sum/2,nums);
    }
};
