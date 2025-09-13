class Solution {
public:
    bool isvowel(char ch){
        string vowel = "aeoiu";
        return vowel.find(ch) != string::npos;
    }
    int maxFreqSum(string s) {
        vector<int> vowel(26,0);
        vector<int> consonent(26,0);

        for(char & ch: s){
            if(isvowel(ch)){
                vowel[ch-'a']++;
            }
            else{
                consonent[ch-'a']++;
            }
        }

        return *max_element(begin(vowel),end(vowel))+*max_element(begin(consonent),end(consonent));
    }
};
