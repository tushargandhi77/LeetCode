class Solution {
public:
    void flip(int idx,vector<int>& nums){
        for(int i = idx;i<(idx+3);i++){
            nums[i] = 1 - nums[i];
        }
    }
    int minOperations(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i = 0;i<n-2;i++){
            if(nums[i] == 0){
                flip(i,nums);
                result++;
            }
        }
        for(int i = 0;i<n;i++){
            cout<<nums[i]<<endl;
            if(nums[i] == 0) return -1;
        }
        return result;
        
    }
};
