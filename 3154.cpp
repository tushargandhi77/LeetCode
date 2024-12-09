class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> result;

        int n = nums.size();
        vector<int> cumsum(n,0);

        for(int i = 1;i<n;i++){
            if((nums[i] %2 == 0 && nums[i-1] % 2 == 0) || (nums[i] %2 != 0 && nums[i-1] % 2 != 0)){
                cumsum[i] = cumsum[i-1] + 1;
            }
            else{
                cumsum[i] = cumsum[i-1];
            }
        }
        for(auto& vec: queries){
            int start = vec[0];
            int end = vec[1];

            if((cumsum[end] - cumsum[start]) > 0){
                result.push_back(false);
            }
            else{
                result.push_back(true);
            }
        }
        return result;
    }
};
