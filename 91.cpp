// Recusion + MEMO
class Solution {
public:
    int t[101];
    int solve(int i,string& s,int& n){
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(t[i] != -1) return t[i];

        int way1 = solve(i+1,s,n);

        int way2 = 0;

        if(i+1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                way2 = solve(i+2,s,n);
            }
        }

        return t[i] = way1 + way2;

    }
    int numDecodings(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,s,n);
    }
};

// Bu

class Solution {
public:
    int numDecodings(string s) {
         int n = s.length();

         vector<int> t(n+1);

         t[n] = 1;

         for(int i = n-1;i>=0;i--){
            if(s[i] == '0'){
                t[i] = 0;
            }
            else{
                t[i] = t[i+1];
                if(i+1 < n){
                    if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                        t[i] += t[i+2];
                    }
                }
            }
         }

         return t[0];
    }
};
