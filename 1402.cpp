// Memo
class Solution {
public:
    int t[501][501];
    int solve(int idx,int time,vector<int>& satisfaction){
        if(idx >= satisfaction.size()) return 0;

        if(t[idx][time] != -1) return t[idx][time];

        int take = satisfaction[idx]*time + solve(idx+1,time+1,satisfaction);

        int not_take = solve(idx+1,time,satisfaction);

        return t[idx][time] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        memset(t,-1,sizeof(t));
        return solve(0,1,satisfaction);
    }
};
