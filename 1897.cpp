// M1 
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;

        int n = words.size();

        if(n == 1) return true;

        for(string s: words){
            for(char ch: s){
                mp[ch]++;
            }
        }

        for(auto it: mp){
            int len = it.second;

            if(len%n != 0) return false;
        }

        return true;
    }
};
