class Solution {
public:
    int t[50001][2];
    int solve(int idx,bool isbuy,vector<int>& prices, int fee){
        if(idx >= prices.size()) return 0;

        if(t[idx][isbuy] != -1) return t[idx][isbuy];

        int profit = 0;

        if(isbuy){
            int take = solve(idx+1,false,prices,fee) - prices[idx];
            int skip = solve(idx+1,true,prices,fee);
            profit = max(take,skip);
        }
        else{
            int sell = prices[idx] + solve(idx+1,true,prices,fee) - fee;
            int not_sell = solve(idx+1,false,prices,fee);
            profit = max(sell,not_sell); 
        }

        return t[idx][isbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(t,-1,sizeof(t));
        return solve(0,true,prices,fee);
    }
};
