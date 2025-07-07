class Solution {
public:
    int t[103][103][103];
    int M = 1e9+7;
    int solve(int idx,int profit,int person,int n,int minProfit, vector<int>& group, vector<int>& profitArr){

        if(person > n) return 0;
        
        if(idx >= profitArr.size()){
            if(profit >= minProfit && person <= n){
                return 1;
            }
            return 0;
        }

        if(t[idx][profit][person] != -1) return t[idx][profit][person];

        int taken = solve(idx+1,min(profit+profitArr[idx],minProfit),person+group[idx],n,minProfit,group,profitArr)%M;
        int not_taken = solve(idx+1,profit,person,n,minProfit,group,profitArr)%M;

        return t[idx][profit][person] = (taken + not_taken)%M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(t,-1,sizeof(t));
        return solve(0,0,0,n,minProfit,group,profit);
    }
};
