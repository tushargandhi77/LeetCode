class Solution {
public:
    int n;
    int t[501][501];
    int solve(int idx,int wall,vector<int>& cost, vector<int>& time){
        if(wall == 0) return 0;

        if(idx >= n) return 1e9;

        if(t[idx][wall] != -1) return t[idx][wall];

        int take = cost[idx] + solve(idx+1,max(0,wall-1-time[idx]),cost,time);

        int skip = solve(idx+1,wall,cost,time);

        return t[idx][wall] = min(take,skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,cost,time); 
    }
};
