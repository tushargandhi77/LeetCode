class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        for(int i = 0;i<n-1;i++){
            int j = i+1;
            sum = 0;
            sum += nums[i];
            while(j < n && nums[i] < nums[j]){
                sum += nums[j];
                i = j;
                j++;
            }
            result = max(sum,result);
        }
        return result;
    }
};
