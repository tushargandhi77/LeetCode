class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;
        int maxRun = 0;

        for(int start=1;start<n;start++){
            if(nums[start-1] < nums[start]){
                currRun++;
            }
            else{
                prevRun = currRun;
                currRun = 1;
            }

            maxRun = max(maxRun,currRun/2);
            maxRun = max(maxRun,min(currRun,prevRun));
        }

        return maxRun;
    }
};
