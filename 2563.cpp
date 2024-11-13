class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        int n = nums.size();

        sort(begin(nums),end(nums));
        for(int i = 0;i<n;i++){

            int idx = lower_bound(begin(nums)+1+i,end(nums),lower-nums[i]) - begin(nums);

            int x = idx - i - 1;

            idx = upper_bound(begin(nums)+1+i,end(nums),upper-nums[i]) - begin(nums);

            int y = idx - i - 1;

            result += (y-x);
        }
        return  result;
    }
};
