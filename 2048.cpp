class Solution {
public:
    bool isbalanced(int num){
        vector<int> count(10);
        while(num > 0){
            int digit = num%10;
            count[digit]++;
            num /= 10;
        }

        for(int i = 0;i<10;i++){
            if(count[i] != 0 && count[i] != i) return false;
        }

        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n+1;i<=1224444;i++){
            if(isbalanced(i)) return i;
        }

        return -1;
    }
};


class Solution {
public:
    vector<int> digitcount{0,1,2,3,4,5,6,7,8,9};

    int backtrack(int n,int curr,int count){
        if(count == 0){
            for(int digit = 1;digit<=9;digit++){
                if(digitcount[digit] != 0 && digitcount[digit] != digit) return 0;
            }
            return curr > n ? curr : 0;
        }

        int result = 0;

        for(int digit = 1;digit <= 9;digit++){
            if(digitcount[digit] > 0 && digitcount[digit] <= count){
                digitcount[digit]--;
                result = backtrack(n,curr*10+digit,count-1);
                digitcount[digit]++;
            }
            if(result != 0){
                break;
            }
        }

        return result;
    }
    int nextBeautifulNumber(int n) {
        int numdigit = to_string(n).length();

        int result = backtrack(n,0,numdigit);

        if( result == 0){
            result = backtrack(n,0,numdigit+1);
        }

        return result;
    }
};
