class Solution {
public:
    int sumdigitnumber(int n){
        int sum = 0;
        while(n>0){
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        vector<int> vec(82,0);

        for(int i = 0;i<n;i++){
            int digitsum = sumdigitnumber(nums[i]);

            if(vec[digitsum] != 0){
                result = max(result,nums[i] + vec[digitsum]);
            }

            vec[digitsum] = max(vec[digitsum],nums[i]);
        }

        return result;
    }
};
