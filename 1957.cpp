class Solution {
public:
    string makeFancyString(string s) {
        string result = "";

        unordered_set<int> st;

        for(int i = 1;i<s.length()-1;i++){
            if(s[i] == s[i-1] && s[i] == s[i+1]){
                st.insert(i);
            }
        }

        for(int i = 0;i<s.length();i++){
            if(st.find(i) != st.end()) continue;

            result += s[i];
        }

        return result;
    }
};


class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int freq = 1;

        result.push_back(s[0]);

        for(int i = 1;i<s.length();i++){
            if(s[i] == result.back()){
                freq++;
                if(freq <= 2){
                    result.push_back(s[i]);
                }
            }
            else{
                freq = 1;
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
