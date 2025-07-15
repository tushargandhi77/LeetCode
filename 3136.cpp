class Solution {
public:
    bool isValid(string word) {
        bool vowel = false;
        bool consonent = false;

        if(word.length() < 3) return false;

        for(char ch: word){
            if(isdigit(ch)){
                continue;
            }
            else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'){
                    vowel = true;
                }
                else{
                    consonent = true;
                }
            }
            else{
                return false;
            }
        }

        return vowel  & consonent;
    }
};
