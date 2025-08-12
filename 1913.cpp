class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();

        int maxD = nums[n-2] * nums[n-1];
        int minD = nums[0] * nums[1];

        return maxD - minD;
    }
};

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for(int& num: nums){
            if(num > secondMax){
                firstMax = secondMax;
                secondMax = num;
            }
            else if(num > firstMax){
                firstMax = num;
            }

            if(num < secondMin){
                firstMin = secondMin;
                secondMin = num;
            }
            else if(num < firstMin){
                firstMin = num;
            }
        }
       

       return firstMax*secondMax - firstMin * secondMin;
    }
};
