// Recursion
class Solution {
public:
    int K;
    int n;
    int solve(int prev,int idx,vector<int>& nums){
        if(idx >= n) return 0;

        int take;
        if(prev == -1 || idx-prev <= K){
            take = nums[idx] + solve(idx,idx+1,nums);
        }

        int skip = solve(prev,idx+1,nums);

        return max(take,skip);
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
        int result = solve(-1,0,nums);

        if(result == 0){
            return *max_element(begin(nums),end(nums));
        }

        return result;
    }
};
