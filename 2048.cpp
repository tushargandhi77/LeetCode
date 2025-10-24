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
