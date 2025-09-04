class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int& num: nums){
            num *= num;
        }

        sort(begin(nums),end(nums));
        return nums;
    }
};
