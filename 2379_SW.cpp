class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int result = INT_MAX;
        int count = 0;
        int i = 0;
        int j = 0;
        int n = blocks.length();
        while(j < n){
            if(blocks[j] == 'W'){
                count++;
            }

            if(j-i+1 == k){
                result = min(count,result);
                if(blocks[i] == 'W') count--;
                i++;
            }
            j++;
        }

        return result;
    }
};
