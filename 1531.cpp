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


class Solution {
public:
    int t[101][101];
    int solve(int i,int k,string& s){
        if(k < 0) return 10001;

        if(i >= s.length() || (s.length()-i) <= k) return 0;

        if(t[i][k] != -1) return t[i][k];

        int delete_i = solve(i+1,k-1,s);

        int keep_i = INT_MAX;

        int deleted = 0;
        int added = 0;
        int freq = 0;
        for(int j = i; j < s.length() && deleted <= k;j++){
            if(s[i] == s[j]){
                freq++;
                if(freq == 2 || freq == 10 || freq == 100){
                    added++;
                }
            }
            else{
                deleted++;
            }
            keep_i = min(keep_i,1 + added + solve(j+1,k-deleted,s));
        }

        return t[i][k] = min(delete_i,keep_i);

    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,k,s);
    }
};
