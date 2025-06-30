class Solution {
public:
    int t[100001][2];
    int solve(int currIdx,int prev,string& s){
        if(currIdx >= s.length()) return 0;

        if(t[currIdx][prev] != -1) return t[currIdx][prev];

        int flip = INT_MAX;
        int non_flip = INT_MAX;
        if(s[currIdx] == '0'){
            if(prev == 0){
                flip = 1 + solve(currIdx+1,1,s);
                non_flip = solve(currIdx+1,0,s);
            }
            else{
                flip = 1 + solve(currIdx+1,1,s);
            }
        }
        else{
            if(prev == 0){
                flip = 1 + solve(currIdx+1,0,s);
                non_flip = solve(currIdx+1,1,s);
            }
            else{
                non_flip = solve(currIdx+1,1,s);
            }
        }

        return t[currIdx][prev] = min(flip,non_flip);
    }
    int minFlipsMonoIncr(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};

// Method 2 Trick

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();

        int count_ones = 0;
        int flip = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == '1'){
                count_ones++;
            }
            else{
                flip = min(count_ones,flip+1);
            }
        }

        return flip;
    }
};
