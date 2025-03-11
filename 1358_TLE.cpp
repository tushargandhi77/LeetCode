class Solution {
public:
    int numberOfSubstrings(string s) {
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        int n = s.length();
        int result = 0;
        for(int i = 0;i<n;i++){
            count_a = 0;
            count_b = 0;
            count_c = 0;
            for(int j = i;j<n;j++){
                if(s[j] == 'a') count_a++;
                if(s[j] == 'b') count_b++;
                if(s[j] == 'c') count_c++;

                if(count_a > 0 && count_b > 0 && count_c > 0){
                    result++;
                }
            }
        }

        return result;
    }
};
