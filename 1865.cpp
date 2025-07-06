// TLE 25 / 26

class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int i = 0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
    }
    
    void add(int index, int val) {
        arr2[index] += val;
    }
    
    int count(int tot) {
        int count = 0;

        for(int i = 0;i<arr2.size();i++){
            count += mp[tot-arr2[i]];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
