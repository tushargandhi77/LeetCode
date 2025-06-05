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


// Method 2

class Solution {
public:
    int t[501][501];
    int solve(string& s1,string& s2,int m,int n){
        if(m == 0 || n == 0) return m+n;

        if(t[m][n] != -1) return t[m][n];

        if(s1[m-1] == s2[n-1]){
            return t[m][n] = solve(s1,s2,m-1,n-1);
        }
        else {
            int insertC = 1 + solve(s1,s2,m,n-1);
            int deleteC = 1 + solve(s1,s2,m-1,n);
            int replaceC = 1 + solve(s1,s2,m-1,n-1);

            return t[m][n] = min({insertC,deleteC,replaceC});
        }

        return -1;
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        memset(t,-1,sizeof(t));

        return solve(word1,word2,m,n);
    }
};
