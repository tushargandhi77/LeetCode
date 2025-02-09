class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        
        int n = nums.size();

        for(int i = 0;i<n;i++){
            nums[i] = nums[i] - i;
        }

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            int totalelement = i;
            int similarelement = mp[nums[i]];
            count += totalelement - similarelement;
            mp[nums[i]]++;
        }
        return count;
    }
};
