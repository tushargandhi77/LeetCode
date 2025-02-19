class Solution {
public:
    void solve(string& curr,vector<string>& result,int n){
        if(curr.length() == n){
            result.push_back(curr);
            return;
        }

        for(char ch= 'a';ch<='c';ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(curr,result,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> result;
        string curr = "";
        solve(curr,result,n);

        if(result.size() < k){
            return "";
        }

        return result[k-1];

    }
};
