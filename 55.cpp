// Recusion 

class Solution {
public:
    int t[10001];
    bool solve(int idx,vector<int>& nums){
        if(idx == nums.size()-1) return true;
        if(idx >= nums.size()) return false;

        if(t[idx] != -1) return t[idx];

        for(int i = 1;i<=nums[idx];i++){
            if(solve(idx+i,nums) == true){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
