class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for(int& fruit: fruits){
            int unset = 1;

            for(int i = 0;i<baskets.size();i++){
                if(fruit <= baskets[i]){
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }

            count+= unset;
        }

        return count;
    }
};
