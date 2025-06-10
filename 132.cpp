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


// Method 3 : 

class Solution {
public:
    int t[2001][2001];
    int solve(int i,int j,string& s,vector<vector<bool>>& d){
        if(i >= j) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(d[i][j]){
            return 0;
        }


        int cuts = INT_MAX;

        for(int k = i;k<=j-1;k++){
            int temp = 1 + solve(i,k,s,d) + solve(k+1,j,s,d);
            cuts = min(cuts,temp);
        }

        return t[i][j] = cuts;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        
        vector<vector<bool>> d(n,vector<bool>(n,false));

        for(int L = 1;L<=n;L++){
            for(int  i = 0;i<(n-L+1);i++){
                int j = i + L -1;
    
                if(i == j){
                    d[i][i] = true;
                }
                else if(i+1 == j){
                    d[i][j] = (s[i] == s[j]);
                }
                else{
                    d[i][j] = ((s[i] == s[j]) && d[i+1][j-1]);
                }
            }
        }
        return solve(0,n-1,s,d);
    }
};


// Method 4 

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int L = 1;L<=n;L++){
            for(int i = 0;i<(n-L+1);i++){
                int j = i + L -1;
                if(i==j){
                    t[i][i] = true;
                }
                else if(i+1 == j){
                    t[i][j] = s[i] == s[j];
                }
                else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }

            }
        }

        vector<int> dp(n);
        for(int i = 0;i<n;i++){
            if(t[0][i] == true){
                dp[i] = 0;
            }
            else{
                dp[i] = INT_MAX;
                for(int k = 0;k<i;k++){
                    if(t[k+1][i] == true && 1 + dp[k] < dp[i]){
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }

        return dp[n-1];
    }
};
