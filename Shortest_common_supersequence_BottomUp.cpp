// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1,0));
        
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i == 0 || j == 0){
                    t[i][j] = (i+j);
                }
                else if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = 1 + min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
};
