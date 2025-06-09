class Solution {

public:
    int count(long curr,long next,int n){
        int currnum = 0;
        while(curr <= n){
            currnum += (next-curr);
            curr *= 10;
            next *= 10;

            next = min(next,long(n+1));
        }
        return currnum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k > 0){
            int countnum = count(curr,curr+1,n);

            if(countnum <= k){
                curr += 1;
                k -= countnum;
            }
            else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
