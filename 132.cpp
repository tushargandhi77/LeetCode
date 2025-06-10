// Method 1 : Recusion + Memo

class Solution {
public:
    int t[2001][2001];
    bool ispalindrome(string& s,int i,int j){
        if(i >= j) return true;

        if(s[i] == s[j]){
            return ispalindrome(s,i+1,j-1);
        }

        return false;
    }
    int solve(int i,int j,string& s){
        if(i >= j) return 0;
        
        if(t[i][j] != -1) return t[i][j];

        if(ispalindrome(s,i,j)){
            return 0;
        }


        int cuts = INT_MAX;

        for(int k = i;k<=j-1;k++){
            int temp = 1 + solve(i,k,s) + solve(k+1,j,s);
            cuts = min(cuts,temp);
        }

        return t[i][j] = cuts;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};


// Method 2 

class Solution {
public:
    int t[2001][2001];
    int d[2001][2001];
    bool ispalindrome(string& s,int i,int j){
        if(i >= j) return true;

        if(d[i][j] != -1) return d[i][j];

        if(s[i] == s[j]){
            return d[i][j] = ispalindrome(s,i+1,j-1);
        }

        return d[i][j] = false;
    }
    int solve(int i,int j,string& s){
        if(i >= j) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(ispalindrome(s,i,j)){
            return 0;
        }


        int cuts = INT_MAX;

        for(int k = i;k<=j-1;k++){
            int temp = 1 + solve(i,k,s) + solve(k+1,j,s);
            cuts = min(cuts,temp);
        }

        return t[i][j] = cuts;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        memset(d,-1,sizeof(d));
        return solve(0,n-1,s);
    }
};
