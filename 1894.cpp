class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum= 0;
        for(int &chalreq: chalk){
            sum += chalreq;
        }

        int remainchalk = k % sum;

        for(int i = 0;i<n;i++){
            if(remainchalk < chalk[i]){
                return i;
            }
            remainchalk -= chalk[i];
        }
        return -1;
    }
};
