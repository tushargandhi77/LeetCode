class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        
        if(n == 1) return 1;

        return n%4 == 0 && isPowerOfFour(n/4);
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        
        while(n%4 == 0){
            n /= 4;
        }

        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;

        double num = log(n)/log(4);

        return (int)num == num;
    }
};
