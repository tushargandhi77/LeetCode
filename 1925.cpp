class Solution {
public:
    bool iseven(int n){
        int count = 0;
        while(n > 0){
            count++;
            n /= 10;
        }
        return count%2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num: nums){
            if(iseven(num)) count++;
        }
        return count;
    }
};
