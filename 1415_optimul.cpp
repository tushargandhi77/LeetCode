class Solution {
public:
    void solve(string& curr,int& k,int n,string& result){
        if(curr.length() == n){
            k--;
            if(k==0){
                result = curr;
            }
            return;
        }

        for(char ch= 'a';ch<='c';ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(curr,k,n,result);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        solve(curr,k,n,result);
        return result;

    }
};
