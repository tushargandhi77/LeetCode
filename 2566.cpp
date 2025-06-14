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
