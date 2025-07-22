class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int max_ans = INT_MIN;

        int sum = 0;
        int i = 0;
        int j = 0;

        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;

            while(mp[nums[j]] >= 2){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }

            max_ans = max(max_ans,sum);
            j++;
        }

        return max_ans;


    }
};
