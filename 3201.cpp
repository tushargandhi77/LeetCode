class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int oddcount = 0;
        int evencount = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] % 2  == 0) evencount++;
            else oddcount++;
        }

        int alternating = 1;
        int parity = nums[0]%2;

        for(int i = 1;i<n;i++){
            int currparity = nums[i]%2;
            if(currparity != parity){
                alternating++;
                parity = currparity;
            }
        }

        return max({oddcount,evencount,alternating});
    }
};
