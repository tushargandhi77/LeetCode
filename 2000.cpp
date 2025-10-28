class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=-1;
        for(int i = 0;i<word.length();i++){
            if(word[i] == ch){
                idx = i;
                break;
            }
        }
        

        reverse(begin(word),end(word)-(word.length()-idx)+1);
        return word;
    }
};
