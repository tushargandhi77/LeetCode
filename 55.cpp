// Recusion + memo

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


// Bottom Up

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n,false);

        t[0] = true;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(t[j] == true && j + nums[j] >= i){
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n-1];
    }
};
