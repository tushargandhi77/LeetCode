class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        int result = -1;
        for(int i = 0;i<n;i++){
            char ch = s[i];

            for(int j = i+1;j<n;j++){
                if(s[j] == ch){
                    result = max(j-i-1,result);
                }
            }
        }

        return result;
    }
};


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        int result = -1;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            
            int idx = s.find_last_of(ch);

            if(idx == i) continue;

            result = max(result,idx-i-1);
        }

        return result;
    }
};

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int result = -1;

        for(int i = 0;i<n;i++){
            char ch = s[i];

            if(mp.find(ch) == mp.end()){
                mp[ch] = i;
            }
            else{
                result = max(result,i-mp[ch]-1);
            }
        } 

        return result;
    }
};
