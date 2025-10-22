class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums),end(nums)) + k;

        vector<int> diff(maxVal+2,0);
        unordered_map<int,int> freq;

        for(int& num: nums){
            freq[num]++;

            int l = max(0,num-k);
            int r = min(num+k,maxVal);

            diff[l]++;
            diff[r+1]--;
        }

        int result = INT_MIN;

        for(int val = 0;val<=maxVal;val++){
            diff[val] += (val > 0 ? diff[val-1] : 0);
            int actual = freq[val];

            int operation = min(numOperations,diff[val] - actual);

            int net = operation + actual;

            result = max(result,net);
        }

        return result;
    }
};
