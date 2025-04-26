class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int minKPosition = -1;
        int maxkPosition = -1;
        int culpritIndex = -1;

        long long result = 0;

        for(int i = 0;i<n;i++){

            if(nums[i] < minK || nums[i] > maxK){
                culpritIndex = i;
            }

            if(nums[i] == minK){
                minKPosition = i;
            }

            if(nums[i] == maxK){
                maxkPosition = i;
            }

            long long temp = min(minKPosition,maxkPosition) - culpritIndex;

            result += temp < 0 ? 0 : temp;
        }

        return result;
    }
};
