// Method 1 :- Using LCS solve Longest Palindrome Subsequence

class Solution {
public:
    int t[1001][1001];
    int LCS(string& s1,string& s2,int m,int n){
        if(m == 0 || n == 0) return 0;

        if(t[m][n] != -1) return t[m][n];

        if(s1[m-1] == s2[n-1]){
            return t[m][n] =  1 + LCS(s1,s2,m-1,n-1);
        }

        return  t[m][n] = max(LCS(s1,s2,m-1,n),LCS(s1,s2,m,n-1));
    }
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        string s1 = s;
        reverse(begin(s),end(s));
        int n = s1.length();

        return LCS(s1,s,n,n);
    }
};

// Method 2 :- Bottom Up LCS

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        string s1 = s;
        reverse(begin(s),end(s));
        string s2 = s;

        vector<vector<int>> t(n+1,vector<int>(n+1,0));

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[n][n];
    }
};


// Method 2 : Recusion and Memo

class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string& s){
        if(i > j) return 0;

        if(i == j) return 1;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]){
            return t[i][j] = 2 + solve(i+1,j-1,s);
        }

        return t[i][j] = max(solve(i+1,j,s),solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        int n = s.length();
        return solve(0,n-1,s);
    }
};
