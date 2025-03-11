class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;

        int n = s.length();
        int result = 0;

        int i = 0;
        int j = 0;

        while(j < n){
            mp[s[j]]++;

            while(i < n && mp.size() == 3){
                result += (n - j);

                char ch = s[i];
                mp[ch]--;
                if(mp[ch] == 0) mp.erase(ch);
                i++;
            }

            j++;
        }

        return result;
    }
};
