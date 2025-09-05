class Solution {
public:
    int MOD = 1e9+7;
    unordered_map<string,int> mp;
    int solve(int idx,int steps,int arrLen){
        if(steps == 0){
            if(idx == 0) return 1;
            return 0;
        }
        
        string key = to_string(idx) + "_" + to_string(steps);

        if(mp.count(key)) return mp[key];

        long stay = solve(idx,steps-1,arrLen);
        
        long left = idx-1 >= 0 ? solve(idx-1,steps-1,arrLen)%MOD : 0;

        long right = idx+1 < arrLen ? solve(idx+1,steps-1,arrLen)%MOD : 0;

        return mp[key] = (stay + left + right)%MOD;
    }
    int numWays(int steps, int arrLen) {
        return solve(0,steps,arrLen);
    }
};


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
