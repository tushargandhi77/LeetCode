class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long,int>> mp(n);

        int result = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                long long diff = (long long)nums[i] - nums[j];

                auto it = mp[j].find(diff);

                int length_j = it == end(mp[j]) ? 0 : it->second;

                mp[i][diff] += length_j + 1;

                result += length_j;
            }
        }

        return result;
    }
};
