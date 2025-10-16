class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        unordered_map<int,int> mp;

        for(int& num: nums){
            int rem = ((num%val)+val) % val;
            mp[rem]++;
        }

        int MEX = 0;

        while(mp[(MEX%val)] > 0){
            mp[(MEX%val)]--;

            MEX++;
        }

        return MEX;
    }
};
