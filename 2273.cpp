class Solution {
public:
    bool checkAnagram(string s1,string s2){
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));

        return s1 == s2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1;i<words.size();i++){
            if(!checkAnagram(words[i],result.back())){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};

class Solution {
public:
    bool checkAnagram(string& s1,string& s2){
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(char& ch: s1){
            v1[ch-'a']++;
        }
        for(char& ch: s2){
            v2[ch-'a']++;
        }

        return v1 == v2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1;i<words.size();i++){
            if(!checkAnagram(words[i],result.back())){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};

class Solution {
public:
    bool checkAnagram(string& s1,string& s2){
        vector<int> v1(26,0);

        for(char& ch: s1){
            v1[ch-'a']++;
        }
        for(char& ch: s2){
            v1[ch-'a']--;
        }

        for(int i = 0;i<26;i++){
            if(v1[i]!=0) return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1;i<words.size();i++){
            if(!checkAnagram(words[i],result.back())){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
