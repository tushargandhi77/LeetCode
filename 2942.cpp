class Solution {
public:
    bool check(string s,char x){
        return s.find(x) != string::npos;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;

        for(int i = 0;i<words.size();i++){
            if(check(words[i],x)){
                result.push_back(i);
            }
        }

        return result;
    }
};
