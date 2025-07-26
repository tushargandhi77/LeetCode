class Solution {
public:
    int N;
    vector<vector<int>> directions{{-2,1},{-1,2},{1,2},{2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    unordered_map<string,double> mp;
    double solve(int r,int c,int k){
        if(r < 0 || r >= N || c < 0 || c >= N) return 0;

        if(k == 0) return 1;

        string key = to_string(r) + "_" + to_string(c) + "_" + to_string(k);

        if(mp.count(key)) return mp[key];

        double result = 0;

        for(auto& dir: directions){
            int r_ = r + dir[0];
            int c_ = c + dir[1];

            result += solve(r_,c_,k-1);
        }

        return mp[key] = result/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        return solve(row,column,k);
    }
};
