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


class Solution {
public:
    int n;
    void solve(int idx,vector<int>& curr,vector<vector<int>>& result,vector<int>& nums){
        if(curr.size() >= 2) result.push_back(curr);

        unordered_set<int> st;
        for(int i = idx;i<n;i++){
            if((curr.empty() || nums[i] >= curr.back()) && st.find(nums[i]) == st.end()){
                curr.push_back(nums[i]);
                solve(i+1,curr,result,nums);
                curr.pop_back();

                st.insert(nums[i]);
            }
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> result;
        vector<int> curr;

        solve(0,curr,result,nums);

        return result;
    }
};
