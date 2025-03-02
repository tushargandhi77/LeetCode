class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;

        for(auto& num: nums1){
            int idx = num[0];
            int val = num[1];

            mp[idx] = val;
        }
        for(auto& num: nums2){
            int idx = num[0];
            int val = num[1];

            mp[idx] += val;
        }

        vector<vector<int>> result;

        for(auto& it : mp){
            result.push_back({it.first,it.second});
        }

        return result;
    }
};
