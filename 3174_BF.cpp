class Solution {
public:
    bool isdigit(char ch){
        if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0'){
            return true;
        }
        return false;
    }
    string clearDigits(string s) {
        string result = "";

        int n = s.length();

        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                s[i] = '.';
                for(int j = i-1;j>=0;j--){
                    if(!isdigit(s[j]) && s[j] != '.'){
                        s[j] = '.';
                        break;
                    }
                }
            }
        }
        for(auto ch : s){
            if(ch != '.'){
                result += ch;
            }
        }
        return result;
    }
};
