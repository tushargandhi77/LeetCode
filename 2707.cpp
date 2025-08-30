class Solution {
public:
    int t[51];
    int solve(int i,string& s,unordered_set<string>& st,int n){
        if(i >= n) return 0;
        
        if(t[i] != -1) return t[i];

        int result = 1 + solve(i+1,s,st,n);

        for(int j = i; j < n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.find(curr) != st.end()){
                result = min(result,solve(j+1,s,st,n));
            }
        }
        return t[i] = result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(),dict.end());
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,s,st,n);
    }
};


class Solution {
public:
    unordered_set<string> st;
    int n;

    int t[51];
    int solve(int idx,string& s){
        if(idx >= n) return 0;

        if(t[idx] != -1) return t[idx];

        string currstr = "";
        int minEle = n;

        for(int i = idx;i<n;i++){
            currstr.push_back(s[i]);

            int currRem = (st.find(currstr) == st.end()) ? currstr.length() : 0;

            int remaining = solve(i+1,s);

            int total_remain = currRem + remaining;

            minEle = min(minEle,total_remain);
        }

        return t[idx] = minEle;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(t,-1,sizeof(t));

        for(string& s: dictionary){
            st.insert(s);
        }

        return solve(0,s);
    }
};
