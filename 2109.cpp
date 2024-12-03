class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";

        int initial = 0;
        int end;
        for(auto& x : spaces){
            end = x;

            while(initial < end){
                result.push_back(s[initial]);
                initial++;
            }
            result.push_back(' ');
        }
        while(end < s.length()){
            result.push_back(s[end]);
            end++;
        }
        return result;
    }
};
