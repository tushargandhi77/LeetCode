class Solution {
public:
    int S;
    int solve(vector<int>& nums,int i,int currsum,int target,vector<vector<int>>& t){
        if(i == nums.size()){
            if(currsum == target) return 1;
            else return 0;
        }

        if(t[i][currsum+S] != -1) return t[i][currsum+S];

        int plus = solve(nums,i+1,currsum+nums[i],target,t);
        int minus = solve(nums,i+1,currsum-nums[i],target,t);

        return t[i][currsum+S] = plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        S = accumulate(begin(nums),end(nums),0);
        int n = nums.size();
        vector<vector<int>> t(n+1,vector<int>(2*S+1,-1));
        return solve(nums,0,0,target,t);
    }
};
