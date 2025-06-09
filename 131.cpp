// Method 1 : - Backtracking
class Solution {
public:
    vector<vector<string>> result;

    bool ispalindrome(string& s,int i,int j){
        if(i >= j) return true;

        if(s[i] == s[j]){
            return ispalindrome(s,i+1,j-1);
        }

        return false;
    }
    void solve(string& s,int idx,vector<string>& curr){
        if(idx >= s.length()){
            result.push_back(curr);
            return;
        }

        for(int i = idx;i<s.length();i++){
            if(ispalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i - idx +1));
                solve(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s,0,curr);
        return result;
    }
};


// Method 2 :- Blue Print + bottom Up


class Solution {
public:
    void solve(int idx,string& s,vector<string>& curr,vector<vector<string>>& result,vector<vector<bool>>& t){
        if(idx == s.length()){
            result.push_back(curr);
            return;
        }

        for(int i = idx;i<s.length();i++){
            if(t[idx][i]){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,curr,result,t);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;

        int n = s.length();

        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int L = 1;L<=n;L++){
            for(int i = 0;i<(n-L+1);i++){
                int j = i + L - 1;
                if(i==j) t[i][i] = true;

                else if(i+1 == j){
                    t[i][j] = s[i] == s[j];
                }
                else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }
            }
        }

        solve(0,s,curr,result,t);
        return result;
    }
};
