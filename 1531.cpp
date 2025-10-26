int t[101][27][101][101];
class Solution {
public:
    // int t[101][27][101][101];
    int solve(int i,int prev,int freq,int k,string& s){
        if(k < 0) return INT_MAX;

        if(i >= s.length()) return 0;

        if(t[i][prev][freq][k] != -1) return t[i][prev][freq][k];

        int del = solve(i+1,prev,freq,k-1,s);

        int keep = 0;
        if(s[i]-'a' != prev){
            keep = 1 + solve(i+1,s[i]-'a',1,k,s);
        }
        else{
            int one_more_add = 0;
            if(freq == 1 || freq == 9 || freq == 99){
                one_more_add = 1;
            }
            keep = one_more_add + solve(i+1,prev,freq+1,k,s);
        }

        return t[i][prev][freq][k] = min(del,keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,26,0,k,s);
    }
};
