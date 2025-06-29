


// Backtracking
class Solution {
public:
    bool isvalid(vector<int>& curr,int target){
        int min = *min_element(begin(curr),end(curr));
        int max = *max_element(begin(curr),end(curr));

        return min+max <= target;
    }
    int solve(int idx,vector<int>& curr,vector<int>& nums,int target){

        int result = 0;
        if(curr.size() > 0 && isvalid(curr,target)){
            result += 1;
        }

        for(int i = idx;i<nums.size();i++){
            curr.push_back(nums[i]);

            result += solve(i+1,curr,nums,target);

            curr.pop_back();
        }

        return result;
    }
    int numSubseq(vector<int>& nums, int target) {
        vector<int> curr;
        return solve(0,curr,nums,target);
    }
};
