class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>& currsubset,vector<vector<int>>& subsets){
        if(idx == nums.size()){
            subsets.push_back(currsubset);
            return;
        }

        currsubset.push_back(nums[idx]);
        solve(nums,idx+1,currsubset,subsets);
        currsubset.pop_back();

        solve(nums,idx+1,currsubset,subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;

        vector<int> currsubset;

        solve(nums,0,currsubset,subsets);

        int result = 0;
        for(auto & subset: subsets){
            int Xor = 0;
            for(auto& num: subset){
                Xor ^= num;
            }
            result += Xor;
        }

        return result;
    }
};
