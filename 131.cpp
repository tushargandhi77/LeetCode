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
