class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(auto& num: nums){
            mp[num]++;
        }

        int result = INT_MIN;
        for(int i = 0;i<n;i++){
            int number = nums[i]+1;
            if(mp[number] == 0) continue;
            result = max(result,mp[number]+mp[nums[i]]);
        }

        return result == INT_MIN ? 0 : result;
    }
};
