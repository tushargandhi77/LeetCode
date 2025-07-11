class Solution {
public:

    bool issinchar(string s,vector<int>& freq){
        vector<int> sfreq(26,0);
        for(char ch: s){
            sfreq[ch-'a']++;
        }

        for(int i = 0;i<26;i++){
            if(sfreq[i] > freq[i]) return false;
        }

        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        vector<int> freq(26,0);
        for(char ch: chars){
            freq[ch-'a']++;
        }
        for(string& s: words){
            if(issinchar(s,freq)){
                result += s.length();
            }
        }

        return result;
    }
};
