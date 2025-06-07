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
