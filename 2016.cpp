// Method 1 : Brute force

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    maxDiff = max(maxDiff,nums[j]-nums[i]);
                }
            }
        }

        return maxDiff;
    }
};


// Method 2 :- Optimul space O(n) and time O(n)

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> LRMin(n,0);
        vector<int> RLMax(n,0);

        for(int i = 0;i<n;i++){
            if(i == 0){
                LRMin[i] = nums[i];
            }
            else{
                LRMin[i] = min(nums[i],LRMin[i-1]);
            }
        }

        for(int i = n-1;i>=0;i--){
            if(i == n-1){
                RLMax[i] = nums[i];
            }
            else{
                RLMax[i] = max(nums[i],RLMax[i+1]);
            }
        }
        int maxDiff = -1;
        for(int i = 0;i<n;i++){
            if(LRMin[i] < RLMax[i]){
                maxDiff = max(maxDiff,RLMax[i]-LRMin[i]);
            }
        }

        return maxDiff;
    }
};
