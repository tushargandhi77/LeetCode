class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        for(int i = 0;i<n;i++){
            int idx = nums[i];
            result[i] = nums[idx];
        }

        return result;
    }
};
