class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> s1;
        unordered_map<int,int> s2;

        for(int& num: nums){
            s1[num]++;
        }

        int i = 0;
        int j = 0;
        int n = nums.size();

        int result = 0;
        while(j < n){
            s2[nums[j]]++;

            while(i < n && s1.size() == s2.size()){
                result += (n-j);
                s2[nums[i]]--;
                if(s2[nums[i]]==0){
                    s2.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};
