class Solution {
public:
    int N;
    vector<vector<int>> result;

    void solve(int idx,vector<int>& nums){
        if(idx >= N){
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for(int i = idx;i<N;i++){
            
            if(st.find(nums[i]) == st.end()){
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);

            solve(idx+1,nums);

            swap(nums[i],nums[idx]);

            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();

        solve(0,nums);

        return result;
    }
};
