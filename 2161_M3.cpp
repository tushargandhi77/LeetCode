class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n,-1);

        int i = 0;
        int j = n-1;

        int idx1 = 0;
        int idx2 = n-1;

        while(i < n && j >= 0){
            if(nums[i] < pivot){
                result[idx1] = nums[i];
                idx1++;
            }
            if(nums[j] > pivot){
                result[idx2] = nums[j];
                idx2--;
            }

            i++;
            j--;
        }
        while(idx1 <= idx2){
            result[idx1] = pivot;
            idx1++;
        }
        return result;
    }
};
