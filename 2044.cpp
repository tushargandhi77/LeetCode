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

// Memo

class Solution {
public:
    int solve(int idx,int currOr,vector<int>& nums,int maxOr,vector<vector<int>>& t){
        if(idx >= nums.size()){
            if(currOr == maxOr) return 1;

            return 0;
        }

        if(t[idx][currOr] != -1) return t[idx][currOr];

        int taken = solve(idx+1,currOr | nums[idx],nums,maxOr,t);

        int not_taken = solve(idx+1,currOr,nums,maxOr,t);

        return t[idx][currOr] = taken + not_taken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int& num: nums){
            maxOr |= num;
        }

        vector<vector<int>> t(nums.size(),vector<int>(maxOr+1,-1));

        return solve(0,0,nums,maxOr,t);
    }
};
