class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int p = nums[i] * nums[j];

                mp[p]++;
            }
        }

        for(auto &it : mp){
            int freq = it.second;

            result += (freq*(freq-1))/2;
        }

        return result*8;
    }
};
