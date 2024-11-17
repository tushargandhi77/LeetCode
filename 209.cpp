class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int j = 0;
        int i = 0;

        int result = INT_MAX;
        int sum = 0;

        while(j<n){
            sum += nums[j];

            while(sum >= target){
                sum -= nums[i];
                result = min(result,j-i+1);
                i++;
            }

            j++;
        }
        return result == INT_MAX ? 0 : result;
    }
};
