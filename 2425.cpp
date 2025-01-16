class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int result = 0;

        for(auto& num: nums1){
            mp[num] += nums2.size();
        }
        for(auto& num: nums2){
            mp[num] += nums1.size();
        }

        for(auto& it: mp){
            int val = it.first;
            int freq = it.second;

            if(freq%2 != 0){
                result ^= val;
            }
        }
        return result;
    }
};
