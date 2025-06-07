// Method 1 :- Recusion

class Solution {
public:
    bool ispalin(int i,int j,string& s){
        if( i >= j) return true;

        if(s[i] == s[j]){
            return ispalin(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string& s) {
        int n = s.length();

        int maxLen = -1;
        string result = "";
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int len = (j-i+1);
                if(ispalin(i,j,s) && len > maxLen){
                    maxLen = len;
                    result = s.substr(i,len);
                }
            }
        }

        return result;
    }
};


// Method 2 :- Memo

class Solution {
public:
    int t[1001][1001];
    bool ispalin(int i,int j,string& s){
        if( i >= j) return true;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]){
            return t[i][j] = ispalin(i+1,j-1,s);
        }
        return t[i][j] = false;
    }
    string longestPalindrome(string& s) {
        int n = s.length();
        memset(t,-1,sizeof(t));

        int maxLen = -1;
        string result = "";
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int len = (j-i+1);
                if(ispalin(i,j,s) && len > maxLen){
                    maxLen = len;
                    result = s.substr(i,len);
                }
            }
        }

        return result;
    }
};

// Method 3 :- Bottom Up Blue Print

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = -1;
        string result = "";

        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int L = 1;L<=n;L++){
            for(int i = 0;(i+L-1)<n;i++){
                int j = (i + L -1);

                if(i == j){
                    t[i][i] = true;
                }
                else if(i+1 == j){
                    t[i][j] = s[i] == s[j];
                }
                else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }
                
                int Len = (j-i+1);
                if(t[i][j] && Len > maxLen){
                    maxLen = Len;
                    result = s.substr(i,maxLen);
                }
            }
        }
        return result;
    }
};
