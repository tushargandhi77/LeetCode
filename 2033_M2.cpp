class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(begin(nums),end(nums));

        int L = (floor)(nums.size()/2);
        int target = nums[L];
        int result = 0;
        for(int& num: nums){
            if(target%x != num%x) return -1;

            result += abs(target-num)/x;
        }

        return result;
    }
};
