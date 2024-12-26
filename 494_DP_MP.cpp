class Solution {
public:
    unordered_map<string,int> mp;

    int solve(vector<int>& nums,int i,int currsum,int target){
        if(i == nums.size()){
            if(currsum == target) return 1;
            else return 0;
        }

        string key = to_string(i) + "_" + to_string(currsum);

        if(mp.count(key)){
            return mp[key];
        }

        int plus = solve(nums,i+1,currsum+nums[i],target);
        int minus = solve(nums,i+1,currsum-nums[i],target);

        return mp[key] = plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
};
