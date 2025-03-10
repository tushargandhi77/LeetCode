class Solution {
public:
    bool isvowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        vector<int> nextcount(n);

        int consonant = n;
        for(int i = n-1;i>=0;i--){
            nextcount[i] = consonant;
            if(!isvowel(word[i])){
                consonant = i;
            }
        }

        int consonantcount = 0;
        unordered_map<char,int> mp;

        int i = 0;
        int j = 0;

        long long result = 0;
        while(j < n){

            char ch = word[j];

            if(isvowel(ch)){
                mp[ch]++;
            }
            else{
                consonantcount++;
            }

            while(i < n && consonantcount > k){
                char ch = word[i];
                if(isvowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }
                else{
                    consonantcount--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && consonantcount == k){
                int idx = nextcount[j];
                result += idx - j;
                char ch = word[i];
                if(isvowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }
                else{
                    consonantcount--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
