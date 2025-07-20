// TLE

class Solution {
public:

    unordered_map<string,int> mp;
    int solve(int idx,int l1,int l2,vector<int>& rods){
        if(idx >= rods.size()){
            if(l1 == l2) return l1;

            return 0;
        }

        string key = to_string(idx) + to_string(l1) + to_string(l2);

        if(mp.count(key)) return mp[key];

        int takeleft = solve(idx+1,l1+rods[idx],l2,rods);
        int takeright = solve(idx+1,l1,l2+rods[idx],rods);
        int nothing = solve(idx+1,l1,l2,rods);

        return  mp[key] = max({takeleft,takeright,nothing});
    }
    int tallestBillboard(vector<int>& rods) {
        return solve(0,0,0,rods);
    }
};
