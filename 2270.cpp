class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        vector<long long> postfixSum(n);

        prefixSum[0] = nums[0];
        postfixSum[n-1] = nums[n-1];

        for(int i = 1;i<n;i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        for(int i = n-2;i>=0;i--){
            postfixSum[i] = nums[i] + postfixSum[i+1];
        }

        int count = 0;
        for(int i = 0;i<n-1;i++){
            if(prefixSum[i] >= postfixSum[i+1]){
                count++;
            }
        }
        return count;
    }
};
