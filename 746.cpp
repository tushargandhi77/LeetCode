class Solution {
public:
    int t[10001];
    int solve(int idx,vector<int>& cost){
        if(idx >= cost.size()){
            return 0;
        }

        if(t[idx] != -1) return t[idx];

        int one_step = solve(idx+1,cost) + cost[idx];
        int two_step = solve(idx+2,cost) + cost[idx];

        return t[idx] = min(one_step,two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        int startwithzero = solve(0,cost);
        memset(t,-1,sizeof(t));
        int startwithone = solve(1,cost);

        return min(startwithzero,startwithone);
    }
};
