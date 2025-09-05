// M1
class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> t;
    int solve(int idx,int steps,int arrLen){
        if(steps == 0){
            if(idx == 0) return 1;
            return 0;
        }
        
        if(t[idx][steps] != -1) return t[idx][steps];

        long stay = solve(idx,steps-1,arrLen);
        
        long left = idx-1 >= 0 ? solve(idx-1,steps-1,arrLen)%MOD : 0;

        long right = idx+1 < arrLen ? solve(idx+1,steps-1,arrLen)%MOD : 0;

        return t[idx][steps] = (stay + left + right)%MOD;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen,steps);

        t.resize(arrLen+1,vector<int>(steps+1,-1));

        return solve(0,steps,arrLen);
    }
};

// M2

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);

        for(int& num: nums){
            freq[num]++;
        }   

        int max_freq = *max_element(begin(freq),end(freq));

        int result = 0;

        for(int i = 0;i<101;i++){
            if(freq[i] == max_freq) result += max_freq;
        }

        return result;
    }
};
