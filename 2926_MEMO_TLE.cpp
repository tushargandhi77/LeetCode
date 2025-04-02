class Solution {
public:
    unordered_map<string,long long> mp;
    long long solve(int prev,int idx,vector<int>& nums){
        if(idx >= nums.size()) return 0;

        string key = to_string(prev) + "_" + to_string(idx);

        if(mp.find(key) != mp.end()){
            return mp[key];
        }

        long long take = 0;
        
        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev){
            take = nums[idx] + solve(idx,idx+1,nums);
        }

        long long not_take = solve(prev,idx+1,nums);

        return mp[key] = max(take,not_take);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxE = *max_element(begin(nums),end(nums));
        if(maxE <= 0) return maxE;
        return solve(-1,0,nums);
    }
};
