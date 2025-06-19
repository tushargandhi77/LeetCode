class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        int minval = nums[0];

        int count = 1;

        for(int i = 1;i<nums.size();i++){
            if((nums[i]-minval)>k){
                count++;
                minval = nums[i];
            }
        }

        return count;
    }
};
