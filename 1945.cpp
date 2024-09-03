class Solution {
public:
    int getLucky(string s, int k) {
        string result = "";
        for(char& ch: s){
            result += to_string(int(ch)-96);
        }
        long long val = 0;
        while(k--){
            val = 0;
            for(char& ch:result){
                val += ch - '0';
            }
            result = to_string(val);
        }
        return val;
    }
};
