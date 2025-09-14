class Solution {
public:
    unordered_set<string> exactset;
    unordered_map<string,string> lower;
    unordered_map<string,string> vowel;

    string toLower(string& s){
        string result = s;
        for(char &ch : result){
            ch = tolower(ch);
        }

        return result;
    }

    string RVowel(string& s){
        string result = s;
        for(char & ch: result){
            if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'){
                ch = '*';
            }
        }

        return result;
    }

    string getAnswer(string& query){
        if(exactset.count(query)){
            return query;
        }

        string lowerstr = toLower(query);
        if(lower.count(lowerstr)){
            return lower[lowerstr];
        }

        string vowelstr = RVowel(lowerstr);
        if(vowel.count(vowelstr)){
            return vowel[vowelstr];
        }

        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        for(string s: wordlist){
            exactset.insert(s);

            string lowerstr = toLower(s);
            if(lower.find(lowerstr) == lower.end()){
                lower[lowerstr] = s;
            }

            string vowelstr = RVowel(lowerstr);
            if(vowel.find(vowelstr) == vowel.end()){
                vowel[vowelstr] = s;
            }
        }

        vector<string> result;
        for(string query: queries){
            result.push_back(getAnswer(query));
        }

        return result;
    }
};
