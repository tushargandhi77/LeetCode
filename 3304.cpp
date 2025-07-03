class Solution {
public:
    string Next(string word){
        string newword = "";

        for(char ch: word){
            if(ch == 'z'){
                newword += 'a';
                continue;
            }
            newword += (ch+1);
        }

        return newword;
    }
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k){
            string nextword = Next(word);

            word += nextword;
        }

        return word[k-1];
    }
};
