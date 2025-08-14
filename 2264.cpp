class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        int n = num.length();

        for(int i = 1;i<n-1;i++){
            if(num[i] == num[i-1] && num[i] == num[i+1]){
                string s = num.substr(i-1,3);
                if(result.empty() || s > result){
                    result = s;
                }
            }
        }

        return result;
    }
};


class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar =  ' ';
        int n = num.length();
        for(int i = 1;i<n-1;i++){
            if(num[i] == num[i-1] && num[i] == num[i+1]){
                maxChar = max(maxChar,num[i]);
            }
        }


        if(maxChar == ' ') return "";

        return string(3,maxChar);
    }
};
