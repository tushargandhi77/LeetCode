class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        if(s1.length() != s2.length()) return false;

        string key = s1 + "_" + s2;

        if(mp.count(key)) return mp[key];


        bool result = false;
        int n = s1.length();
        for(int i = 1;i<n;i++){
            
            bool notswap = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i));

            bool swap = isScramble(s1.substr(i,n-i),s2.substr(0,n-i)) && isScramble(s1.substr(0,i),s2.substr(n-i,i));

            if(notswap || swap){
                result = true;
            } 

        }

        return mp[key] = result;
    }
};
