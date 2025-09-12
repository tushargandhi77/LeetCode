class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(begin(s),end(s),[](char ch){
            return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
        });
    }
};

class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(begin(s),end(s),[](char ch){
            string vowel = "aeoiu";
            return vowel.find(ch) != string::npos;
        });
    }
};
