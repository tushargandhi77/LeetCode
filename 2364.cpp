class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            int diff = nums[i] - i;

            int total = i;
            int same = mp[diff];

            result += total - same;

            mp[diff]++;
        }
        return result;
    }
};
