class Solution {
public:
    int lowerBound(vector<int>& nums,int target){
        int l = 0;
        int r = nums.size() - 1;
        int result = nums.size();

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                result = mid;
                r = mid - 1;
            }
        }
        return result;
    }
    int maximumCount(vector<int>& nums) {
        int P_idx = lowerBound(nums,1);
        int N_idx = lowerBound(nums,0);
        int n = nums.size();
        return max(n-P_idx,N_idx);
    }
};
