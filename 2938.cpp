class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        long long swap = 0;
        
        for(long long i = 0;i<s.length();i++){
            if(s[i] == '1'){
                count++;
            }

            if(s[i] == '0'){
                swap += count;
            }
        }
        return swap;
    }
};
