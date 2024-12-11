class Solution {
public:
    int BinarySearch(vector<int> & nums,int target){
        int res = 0;
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid] <= target){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));

        int result = 0;

        for(int  i = 0;i<n;i++){
            int x = nums[i];
            int y = x+2*k;
            int j = BinarySearch(nums,y);

            result = max(result,j-i+1);

        }
        return result;
    }
};
