class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;
    void solve(int idx,vector<int>& temp,vector<int>& nums){
        if(idx >= nums.size()){
            if(temp.size() >= 2 && st.find(temp) == st.end()){
                result.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        if(temp.empty() || temp.back() <= nums[idx]){
            temp.push_back(nums[idx]);
            solve(idx+1,temp,nums);
            temp.pop_back();
        }

        solve(idx+1,temp,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0,temp,nums);

        return result;
    }
};
