// log n

class Solution {
public:
    int numberOfMatches(int n) {
        int result = 0;

        while(n > 1){
            if(n%2 == 0){
                result += n/2;
                n = n/2;
            }
            else{
                result += (n-1)/2;
                n = (n + 1)/2;
            }
        }

        return result;
    }
};

// O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};
