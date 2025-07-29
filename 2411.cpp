class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n,0);
        vector<int> maxbit(32,-1);

        for(int i = n-1;i>=0;i--){
            int maxEnd = i;

            for(int j = 0;j<32;j++){
                if(!(nums[i] & (1 << j))){
                    if(maxbit[j] != -1){
                        maxEnd = max(maxEnd,maxbit[j]);
                    }
                }
                else{
                    maxbit[j] = i;
                }
            }

            result[i] = maxEnd - i + 1;
        }

        return result;
    }
};
