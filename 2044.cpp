// Recursion

class Solution {
public:

    int solve(int idx,int currOr,vector<int>& nums,int maxOr){
        if(idx >= nums.size()){
            if(currOr == maxOr) return 1;

            return 0;
        }

        int taken = solve(idx+1,currOr | nums[idx],nums,maxOr);

        int not_taken = solve(idx+1,currOr,nums,maxOr);

        return taken + not_taken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int& num: nums){
            maxOr |= num;
        }

        return solve(0,0,nums,maxOr);
    }
};
