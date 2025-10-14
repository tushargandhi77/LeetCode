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


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }
            else{
                prevRun = currRun;
                currRun = 1;
            }

            if(currRun / 2 >= k){
                return true;
            }
            
            if(min(currRun,prevRun) >= k){
                return true;
            }
        }

        return false;
    }
};
