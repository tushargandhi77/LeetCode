class Solution {
public:
    int solve(int l,int r,vector<int>& nums){
        int prev = 0;
        int prev_prev = 0;

        for(int i = l;i<=r;i++){
            int skip = prev;
            int steal = nums[i] + prev_prev;

            int temp = max(skip,steal);

            prev_prev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        int take_first = solve(0,n-2,nums);
        int not_take_first = solve(1,n-1,nums);

        return max(take_first,not_take_first);
    }
};
