class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(int& num: nums){
            mp2[num]++;
        }
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int n1 = i+1;
            int n2 = n-i-1;

            mp1[nums[i]]++;
            mp2[nums[i]]--;

            if(mp1[nums[i]] > (n1/2) && mp2[nums[i]] > (n2/2)){
                return i;
            }
        }

        return -1;
    }
};
