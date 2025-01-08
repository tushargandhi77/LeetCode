class Solution {
public:
    bool isprefixandsufix(string& s1,string& s2){
        if(s1.length() > s2.length()) return false;
        int idx = s2.length() - s1.length();
        if(s2.substr(0,s1.length()) == s1 && s2.substr(idx)==s1) return true;

        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int result = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(i == j) continue;

                if(isprefixandsufix(words[i],words[j])) result++;
            }
        }
        return result;
    }
};
