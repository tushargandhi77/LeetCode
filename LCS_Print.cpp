class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> t(m+1,vector<int>(n+1,0));

        string lcs = "";

        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int i = m,j = n;
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                lcs.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j] > t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(begin(lcs),end(lcs));
        cout<<lcs<<endl;

        return t[m][n];
    }
};
