// Brute Force

class Solution {
public:
    int divide(int a,int b){
        while(a%b == 0){
            a = a/b;
        }
        return a;
    }

    bool isugly(int n){
        n = divide(n,2);
        n = divide(n,3);
        n = divide(n,5);

        return n == 1;
    }
    int nthUglyNumber(int n) {
        int count = 0;

        for(int i = 1;i<1e9;i++){
            if(isugly(i)){
                count++;
                if(count==n) return i;
            }
        }

        return -1;
    }
};

// Optimul
