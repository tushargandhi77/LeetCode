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


// 

class Solution {
public:
    int t[21][10001];
    int solve(int idx,int diff,vector<int>& rods){
        if(idx >= rods.size()){
            if(diff == 0) return 0;

            return INT_MIN;
        }

        if(t[idx][diff+5000] != -1) return t[idx][diff+5000]; // diff may negative

        int take_l1 = rods[idx] + solve(idx+1,diff+rods[idx],rods); // l1 - l2 = diff, l1 + x - l2 => l1-l2 + x => diff + x

        int take_l2 = rods[idx] + solve(idx+1,diff-rods[idx],rods); // l1 - l2 = diff, l1  - (l2 + x)  => l1-l2 - x => diff - x

        int nothing = solve(idx+1,diff,rods);

        return t[idx][diff+5000] = max({take_l1,take_l2,nothing});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(t,-1,sizeof(t));
        return solve(0,0,rods)/2; // because solve return full length and answer will be half
    }
};
