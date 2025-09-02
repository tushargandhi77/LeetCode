class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        int result = -1;
        for(int i = 0;i<n;i++){
            char ch = s[i];

            for(int j = i+1;j<n;j++){
                if(s[j] == ch){
                    result = max(j-i-1,result);
                }
            }
        }

        return result;
    }
};


