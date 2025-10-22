class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> diff;
        unordered_map<int,int> freq;
        int maxval = *max_element(begin(nums),end(nums)) + k;

        for(int & num: nums){
            freq[num]++;

            int l = max(0,num-k);
            int r = min(maxval,num+k);

            diff[l]++;
            diff[r+1]--;

            diff[num] += 0;
        }

        int result = 1;
        int cumsum = 0;
        for(auto it = diff.begin();it != diff.end();it++){
            int target = it->first;

            it->second += cumsum;

            int targetfreq = freq[target];

            int required = it->second-targetfreq;

            int operation = min(required,numOperations);

            result = max(result,operation+targetfreq);

            cumsum = it->second;
        }   

        return result;
    }
};
