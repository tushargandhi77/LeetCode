class Solution {
public:

    void solve(int idx,vector<int>& nums,vector<int>& temp,vector<int>& result,int prev){
        if(idx >= nums.size()){
            if(result.size() < temp.size()){
                result = temp;
            }
            return;
        }


        if(prev == -1 || nums[idx] % prev == 0 ){
            temp.push_back(nums[idx]);
            solve(idx+1,nums,temp,result,nums[idx]);
            temp.pop_back();
        }

        solve(idx+1,nums,temp,result,prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> result;
        vector<int> temp;

        solve(0,nums,temp,result,-1);

        return result;
    }
};
