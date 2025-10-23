class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() != 2){
            string temp;
            for(int i = 1;i<s.length();i++){
                int val = ((s[i]-'0') + (s[i-1]-'0'))%10;
                temp += to_string(val);
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};
