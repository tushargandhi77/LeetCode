class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        unordered_set<char> st(begin(brokenLetters),end(brokenLetters));

        int count = 0;
        string word;
        while(ss >> word){
            bool isfind = false;
            for(char& ch: word){
                if(st.find(ch) != st.end()){
                    isfind = true;
                    break;
                }
            }
            if(isfind==false) count++;
        }

        return count;
    }
};
