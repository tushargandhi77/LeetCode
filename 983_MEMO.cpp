class Solution {
public:
    int N;
    int t[366];
    int getidx(vector<int>& days,int idx,const int seven){
        int day;
        if(seven == 1){
            day = days[idx] + 6;
        }
        else{
            day = days[idx] + 29;
        }
        int res = 0;
        for(int i = idx;i<N;i++){
            if(days[i]<=day){
                res++;
            }
        }
        return res;
    }
    
    int solve(vector<int>& days,vector<int>& costs,int i){
        if(i>=N) return 0;

        if(t[i] != -1) return t[i];

        int take_2 = solve(days,costs,i+1) + costs[0];
        int take_7 = solve(days,costs,i+getidx(days,i,1)) + costs[1];
        int take_30 = solve(days,costs,i+getidx(days,i,0)) + costs[2];

        return t[i] = min({take_2,take_7,take_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        N = days.size();
        memset(t,-1,sizeof(t));
        return solve(days,costs,0);
    }
};
