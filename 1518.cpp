class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;

        while(numBottles > 0){
            int net = numBottles/numExchange;
            int rem = numBottles%numExchange;
            
            if(net == 0) break;
        
            result += net;

            numBottles = (net+rem);

        }

        return result;
    }
};
