// M1

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(begin(nums2),end(nums2));
    
        for(int i = 0;i<nums1.size();i++){
            if(st.find(nums1[i]) != st.end()){
                return nums1[i];
            }
        }

        return -1;
    }
};
