class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));

        int Minprice = prices[0] + prices[1];

        return money - Minprice < 0 ? money : money - Minprice;
    }
};
