

// BAcktracking

class Solution {
public:

    bool ismax(vector<int>& result,vector<int>& curr){
        if(result.empty()) return true;

        int result_sum = accumulate(begin(result),end(result),0);
        int curr_sum = accumulate(begin(curr),end(curr),0);

        return curr_sum > result_sum;
    }
    void Backtracking(int idx,int k,vector<int>& nums,vector<int>& curr,vector<int>& result){
        if(idx > nums.size()) return;

        if(curr.size() == k && ismax(result,curr)){
            result = curr;
        }

        for(int i = idx;i<nums.size();i++){

            // Do
            curr.push_back(nums[i]);

            // Explore
            Backtracking(i+1,k,nums,curr,result);

            // Undo
            curr.pop_back();
        }
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> curr;
        vector<int> result;

        Backtracking(0,k,nums,curr,result);

        return result;
    }
};
