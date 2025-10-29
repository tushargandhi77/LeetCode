class Solution {
public:
    int smallestNumber(int n) {
        int result = 0;

        for(int i = 1;i<=10;i++){
            int val = (1 << i)-1;
            if(val >= n) return val;
        }
        return -1;
    }
};

class Solution {
public:
    bool checkset(int n){
        return ((n & (n+1)) == 0);
    }
    int smallestNumber(int n) {
        int result = n;

        while(!checkset(result)){
            result++;
        }

        return result;
    }
};

class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;
        while(1){
            if(result >= n) return result;
            result = (2*result + 1);
        }

        return result;
    }
};

class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;
        
        return (1<<bits) - 1 ;
    }
};

