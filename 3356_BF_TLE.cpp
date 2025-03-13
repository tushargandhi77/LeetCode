class Solution {
public:
    void transform(vector<int>& nums,vector<int>& vec){
        int l = vec[0];
        int r = vec[1];
        int val = vec[2];

        for(int i = l;i <= r;i++){
            int new_val = nums[i] - val;
            if(new_val < 0){
                nums[i] = 0;
            }
            else{
                nums[i] = new_val;
            }
        }
    }

    bool check(vector<int>& nums){
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        if(check(nums)) return 0;

        for(int i = 0;i < queries.size() ; i++){
            transform(nums,queries[i]);

            if(check(nums)){
                return i+1;
            }
        }
        return -1;
    }
};
