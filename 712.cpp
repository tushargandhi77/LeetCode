class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string& s1,string& s2){
        if(i == s1.length() && j == s2.length()){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        if(i == s1.length()){
            return s2[j] + solve(i,j+1,s1,s2);
        }

        if(j == s2.length()){
            return s1[i] + solve(i+1,j,s1,s2);
        }

        if(s1[i] == s2[j]) return solve(i+1,j+1,s1,s2);

        int option1 = s1[i] + solve(i+1,j,s1,s2);
        
        int option2 = s2[j] + solve(i,j+1,s1,s2);

        return t[i][j] = min(option1,option2);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s1,s2);
    }
};
