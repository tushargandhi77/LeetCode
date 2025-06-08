// Method 1 :- Recusion + Memo
class Solution {
public:
    int t[501][501];
    int solve(int i,int j,string& s){
        if(i >= j) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]){
            return t[i][j] = solve(i+1,j-1,s);
        }

        int option1 = 1 + solve(i+1,j,s);
        int option2 = 1 + solve(i,j-1,s);

        return t[i][j] = min(option1,option2);
    }
    int minInsertions(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};


// Method 2: - Bottom Up

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        
        vector<vector<int>> t(n,vector<int>(n,0));

        for(int L = 2;L<=n;L++){
            for(int i = 0;i<(n-L+1);i++){
                int j = i + L -1;

                if(s[i] == s[j]){
                    t[i][j] = t[i+1][j-1];
                }
                else{
                    t[i][j] = 1 + min(t[i+1][j],t[i][j-1]);
                }
            }
        }

        return t[0][n-1];
    }
};
