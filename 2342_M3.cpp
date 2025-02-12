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

        vector<pair<int,int>> sumNum(n);

        for(int i = 0;i<n;i++){
            int sumdigit = sumdigitnumber(nums[i]);
            sumNum[i] = {sumdigit,nums[i]};
        }


        sort(sumNum.begin(),sumNum.end());
        int result = -1;
        for(int i = 1;i<n;i++){
            if(sumNum[i].first == sumNum[i-1].first){
                result = max(result,sumNum[i].second+sumNum[i-1].second);
            }
        }

        return result;
    }
};
