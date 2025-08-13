class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));

        int Minprice = prices[0] + prices[1];

        return money - Minprice < 0 ? money : money - Minprice;
    }
};


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for(int& num: prices){
            if(num < firstMin){
                secondMin = firstMin;
                firstMin = num;
            }
            else if(num < secondMin){
                secondMin = num;
            }
        }

        int Minprice = firstMin + secondMin;

        return money - Minprice < 0 ? money : money - Minprice;
    }
};
