class Solution {
public:
    int m;
    int n;
    int t[501][501];
    int solve(int i,int j,string& s1,string& s2){
        if(i == m){
            return n - j;
        }
        else if(j == n){
            return m - i;
        }

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return  solve(i+1,j+1,s1,s2);
        }

        int insert = 1 + solve(i,j+1,s1,s2);
        int dele   = 1 + solve(i+1,j,s1,s2);
        int replace = 1 + solve(i+1,j+1,s1,s2);

        return t[i][j] = min({insert,dele,replace});
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,word1,word2);
    }
};
