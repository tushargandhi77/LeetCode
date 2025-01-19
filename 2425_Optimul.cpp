class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;

        if(nums1.size()%2 != 0){
            for(auto& num: nums2){
                result ^= num;
            }
        }

        if(nums2.size()%2 != 0){
            for(auto& num: nums1){
                result ^= num;
            }
        }
        return result;
    }
};