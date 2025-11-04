class Solution {
public:
    vector<vector<unordered_map<int,int>>> dp;
    int solve(int i,int j,int addval,vector<int>& nums,vector<int>& addValues){
        if(i >= nums.size()){
            if(j >= addValues.size()) return 0;
            return 1e9;
        }
        else if(j >= addValues.size()) return 1e9;

        if(dp[i][j].count(addval)) return dp[i][j][addval];

        int include = 1e9;
        if((addval & nums[i]) == addValues[j]){
            include = nums[i] + solve(i+1,j+1,(1<<17)-1,nums,addValues);
        }
        
        int exclude = solve(i+1,j,addval & nums[i],nums,addValues);

        return dp[i][j][addval] = min(include,exclude);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        dp.resize(nums.size()+1,vector<unordered_map<int,int>>(11));

        int result = solve(0,0,(1<<17)-1,nums,andValues);
        return result == 1e9 ? -1 : result;
    }
};
