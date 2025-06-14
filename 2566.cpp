class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        char maxChar;
        char minChar;
        for(char c: s){
            if(c != '9'){
                maxChar = c;
                break;
            }
        }
        for(char c:s){
            if(c != '0'){
                minChar = c;
                break;
            }
        }

        string s1 = s;
        string s2 = s;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] == maxChar){
                s1[i] = '9';
            }
        }
        for(int i = 0;i<s2.length();i++){
            if(s2[i] == minChar){
                s2[i] = '0';
            }
        }

        int result = stoi(s1) - stoi(s2);
    

        return result;
    }
};


// Method 2 : with StL

class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);

        string str2 = str1;

        int maxIdx = str1.find_first_not_of('9');

        if(maxIdx != string::npos){
            char ch = str1[maxIdx];
            replace(begin(str1),end(str1),ch,'9');
        }

        int minIdx = str2.find_first_not_of('0');

        if(minIdx != string::npos){
            char ch = str2[minIdx];
            replace(begin(str2),end(str2),ch,'0');
        }

        return stoi(str1) - stoi(str2);
    }
};
