class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,1);

        for(int i = 0;i<n;i++){
            int val = t[i];
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){
                    t[i] = max(t[i],t[j]+val);
                }
            }
        }
        return *max_element(begin(t),end(t));
    }
};
