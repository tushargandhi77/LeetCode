// 65 cases passed total of 66
class Solution {
public:
    bool isprime(int num){
        for(int i = 2;i<=sqrt(num);i++){
            if(num%i == 0){
                return false;
            }
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> test;

        for(int i = left;i<=right;i++){
            if(isprime(i)){
                test.push_back(i);
            }
        }

        int n = test.size();
        int num1 = -1;
        int num2 = -1;

        if(n == 0 || n == 1) return {num1,num2};
        int min = INT_MAX;
        for(int i = 1;i<n;i++){
            if((test[i]-test[i-1]) < min){
                min = (test[i] - test[i-1]);
                num1 = test[i-1];
                num2 = test[i];
            }
        }

        return {num1,num2};
    }
};
