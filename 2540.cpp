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

// M2 
class Solution {
public:
    bool binarysearch(int num,vector<int>& nums){
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(num == nums[mid]) return true;
            if(num < nums[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        for(int i = 0;i<n;i++){
            int num = nums1[i];

            if(binarysearch(num,nums2)) return num;
        }

        return -1;
    }
};
