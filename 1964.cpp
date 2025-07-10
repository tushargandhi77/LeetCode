class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();

       vector<int> LIS;
       vector<int> result(n,0);

       for(int i = 0;i<n;i++){
        int idx = upper_bound(begin(LIS),end(LIS),nums[i]) - begin(LIS);

        if(idx == LIS.size()){
            LIS.push_back(nums[i]);
        }
        else{
            LIS[idx] = nums[i];
        }

        result[i] = idx+1;
       }

       return result;
    }
};
