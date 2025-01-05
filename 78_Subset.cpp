class Solution {
public:
    int N;
    vector<vector<int>> result;
    void solve(int idx,vector<int>& nums,vector<int>& temp){
        if(idx >= N){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(idx+1,nums,temp);
        temp.pop_back();

        solve(idx+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
          N = nums.size();
          vector<int> temp;
          solve(0,nums,temp);  
          return result;

    }
};
