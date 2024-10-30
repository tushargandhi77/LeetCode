class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n,1);
        vector<int> LDS(n,1);


        // LIS
        for(int i = 0;i<n;i++){
            for(int j = i-1 ; j>=0;j--){
                if(nums[i] > nums[j]){
                LIS[i] = max(LIS[i],LIS[j] + 1);
                }
            }
        }

        // LDS

        for(int i =  n-1;i>= 0 ;i--){
            for(int j = i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i],LDS[j] + 1);
                }
            }
        }

        int minremoval = INT_MAX;

        for(int i = 0;i<n;i++){
            if(LIS[i] > 1 && LDS[i] > 1){// mountain array mininum length tahbhi >= 3 aa payega 
            minremoval = min(minremoval,n-LIS[i] - LDS[i] + 1);
            }
        }

        return minremoval;
    }
};