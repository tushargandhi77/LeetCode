class Solution {
public:
    unordered_map<char,string> mp;
    vector<string> result;

    void solve(int idx,string& digit,string& temp){
        if(idx >= digit.size()){
            result.push_back(temp);
            return;
        }

        char ch = digit[idx];
        string str = mp[ch];

        for(int i = 0;i<str.length();i++){
            temp.push_back(str[i]);

            solve(idx+1,digit,temp);

            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        solve(0,digits,temp);

        return result;

    }
};
