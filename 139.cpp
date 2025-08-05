class Solution {
public:
    int t[301];
    bool solve(int idx,string& s,unordered_set<string>& st){
        if(idx == s.length()){
            return true;
        }   

        if(t[idx] != -1) return t[idx];

        for(int j = idx;j<s.length();j++){
            string sub = s.substr(idx,j-idx+1);

            if(st.count(sub) && solve(j+1,s,st)) return t[idx] = true;
        }

        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict),end(wordDict));

        if(st.count(s)) return true;

        memset(t,-1,sizeof(t));

        return solve(0,s,st);
    }
};
