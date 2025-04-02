class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        int maxE = *max_element(begin(nums),end(nums));
        if(maxE <= 0) return maxE;

        vector<long long> t(n);
        for(int i = 0;i<n;i++){
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if((nums[j] - j) <= (nums[i] - i)){
                    t[i] = max<long long> (t[i],t[j] + nums[i]);
                    maxSum = max(maxSum,t[i]);
                }

            }
        }

        return maxSum > maxE ? maxSum : maxE;
    }
};
