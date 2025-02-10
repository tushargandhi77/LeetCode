class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx,int k,int target,vector<int> & temp){
        if(target == 0 && k == 0){
            result.push_back(temp);
            return;
        }
        if(target < 0 || k < 0) return;

        for(int i = idx;i<=9;i++){
            temp.push_back(i);
            solve(i+1,k-1,target-i,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1,k,n,temp);
        return result;
    }
};
