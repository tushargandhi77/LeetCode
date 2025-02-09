class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx,vector<int>& candidates,int target,vector<int>& curr){
        if(idx > candidates.size()) return;

        if(target == 0){
            result.push_back(curr);
            return;
        }
        if(target < 0) return;

        for(int i = idx;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> curr;
        solve(0,candidates,target,curr);
        return result;
    }
};
