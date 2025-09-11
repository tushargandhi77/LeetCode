// M`
class Solution {
public:
    bool isvowel(char ch){
        string s = "AEOIUaeoiu";
        return s.find(ch) != string::npos;
    }
    string sortVowels(string s) {
        string temp;

        for(char ch:s){
            if(isvowel(ch)){
                temp.push_back(ch);
            }
        }

        sort(begin(temp),end(temp));

        int j = 0;
        for(int i = 0;i<s.length();i++){
            if(isvowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }

        return s;
    }
};
