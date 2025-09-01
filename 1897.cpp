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
// M2

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mp(26,0);

        int n = words.size();

        if(n == 1) return true;

        for(string s: words){
            for(char ch: s){
                mp[ch-'a']++;
            }
        }

        for(int len: mp){

            if(len%n != 0) return false;
        }

        return true;
    }
};

// M3 

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mp(26,0);

        int n = words.size();

        if(n == 1) return true;

        for(string s: words){
            for(char ch: s){
                mp[ch-'a']++;
            }
        }

        auto lambda = [&](int freq){
            return freq%n == 0;
        };

        return all_of(begin(mp),end(mp),lambda);
    }
};
