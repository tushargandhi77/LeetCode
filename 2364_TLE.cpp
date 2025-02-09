class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((j-i) != (nums[j]-nums[i])){
                    count++;
                }
            }
        }
        return count;
    }
};
