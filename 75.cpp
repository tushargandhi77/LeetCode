class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }

        int j = 0;
        for(int i = 0;i<=2;i++){
            while(mp[i] != 0){
                nums[j] = i;
                j++;
                mp[i]--;
            }
        }

    }
};
