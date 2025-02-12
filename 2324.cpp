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
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            int digitsum = sumdigitnumber(nums[i]);

            if(mp.count(digitsum)){
                result = max(result,nums[i] + mp[digitsum]);
            }

            mp[digitsum] = max(mp[digitsum],nums[i]);
        }

        return result;
    }
};
