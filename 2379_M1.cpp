class Solution {
public:
    int calmin(int i,string blocks,int k){
        int end = i+k;
        int count = 0;
        while(i < end){
            if(blocks[i] == 'W'){
                cout<<i<<endl;
                count++;
            }
            i++;
        }
        return count;
    }
    int minimumRecolors(string blocks, int k) {
        int result = INT_MAX;

        for(int i = 0;(i+k)<=blocks.length();i++){
            result = min(result,calmin(i,blocks,k));
        }
        return result;
    }
};
