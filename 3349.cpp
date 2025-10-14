class Solution {
public:
    bool IsIncreasing(int start,int end,vector<int>& nums){
        for(int i = start+1;i<end;i++){
            if(nums[i-1] >= nums[i]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int start = 0;start+2*k<=n;start++){
            bool first = IsIncreasing(start,start+k,nums);
            bool second = IsIncreasing(start+k,start+2*k,nums);

            if(first && second) return true;
        }

        return false;
    }
};
