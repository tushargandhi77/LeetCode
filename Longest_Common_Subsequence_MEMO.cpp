class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string& s1,string &s2){
        if(i>=s1.length() || j >= s2.length()) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j] = 1 + solve(i+1,j+1,s1,s2);
        }

        int take = solve(i,j+1,s1,s2);
        int not_take = solve(i+1,j,s1,s2);

        return t[i][j] = max(take,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};
