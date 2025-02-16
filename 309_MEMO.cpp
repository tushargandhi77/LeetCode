class Solution {
public:
    int t[5001][2];
    int solve(int day,int n,vector<int>& prices,bool buy){
        if(day >= n) return 0;

        if(t[day][buy] != -1) return t[day][buy];

        int profit = 0;
        if(buy){
            int take = solve(day+1,n,prices,false) - prices[day];
            int not_take = solve(day+1,n,prices,true);
            profit = max({profit,take,not_take});
        }
        else{
            int sell = prices[day] + solve(day+2,n,prices,true);
            int not_sell = solve(day+1,n,prices,false);
            profit = max({profit,sell,not_sell});
        }
        return t[day][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        memset(t,-1,sizeof(t));
        int n = prices.size();
        return solve(0,n,prices,buy);
    }
};
