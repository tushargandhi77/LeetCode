class Solution {
public:
    int n;
    vector<int> t;
    bool solve(int i,vector<int>& nums){
        if(i >= n) return true;

        if(t[i] != -1) return t[i];

        bool result = false;


        // case 1
        if(i+1 < n && nums[i] == nums[i+1]){
            result = solve(i+2,nums);
            if(result == true) return t[i] = true;
        }

        // case 2

        if(i + 2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
            result = solve(i+3,nums);
            if(result == true) return t[i] = true;
        }

        // case 3

        if(i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1){
            result = solve(i+3,nums);
        }

        return t[i] = result;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        t.resize(n+1,-1);
        return solve(0,nums);       
    }
};
