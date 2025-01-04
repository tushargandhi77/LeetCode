class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_map<char,vector<int>> mp;
        for(int i = 0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int result = 0;
        for(auto& [c,vec] : mp){
            int u = vec[0];
            int v = vec[vec.size()-1];
            unordered_set<char> st;
            if(u==v) continue;
            for(int i=u+1;i<v;i++){
                if(st.find(s[i]) == st.end()){
                    result++;
                    st.insert(s[i]);
                }
            }
        }
        return result;
    }
};
