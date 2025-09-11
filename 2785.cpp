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


// M2 

class Solution {
public:
    bool isvowel(char ch){
        string s = "AEOIUaeoiu";
        return s.find(ch) != string::npos;
    }
    string sortVowels(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(char &ch: s){
            if(isvowel(ch)){
                mp[ch]++;
            }
        }

        string temp = "AEIOUaeiou";

        int j = 0;

        for(int i = 0;i<n;i++){
            if(isvowel(s[i])){
                while(mp[temp[j]] == 0){
                    j++;
                }

                s[i] = temp[j];
                mp[temp[j]]--;
            }
        }

        return s;
    }
};
