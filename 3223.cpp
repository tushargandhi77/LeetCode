class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;

        for(char& ch: s){
            mp[ch]++;
        }

        int result = 0;
        for(auto& it:mp){
            int val = it.second;
            if(val <= 2){
                result+= val;
                continue;
            }

            if(val%2 == 0){
                result += 2;
            }
            else{
                result+= 1;
            }
        }
        return result;
    }
};
