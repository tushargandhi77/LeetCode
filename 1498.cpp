// Optimul

class Solution {
public:
    int M = 1e9+7;

    
    int numSubseq(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();

        sort(begin(nums),end(nums));

        vector<int> power(n);

        power[0] = 1;

        for(int i = 1;i<n;i++){
            power[i] = (power[i-1] * 2) % M;
        }

        int i = 0;
        int j = n - 1;

        while(i <= j){
            if(nums[i]+nums[j] <= target){
                result = (result % M + power[j-i])%M;
                i++;
            }
            else{
                j--;
            }
        }

        return result;
    }
};


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
