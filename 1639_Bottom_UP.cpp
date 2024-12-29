class Solution {
public:
    int m;
    int k;
    const int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].size();

        vector<vector<long long>> freq(26,vector<long long>(k));
        for(int col = 0;col<k;col++){
            for(string& str: words){
                char ch = str[col];
                freq[ch-'a'][col]++;
            }
        }

        vector<vector<int>> t(m+1,vector<int>(k+1,0));
        t[0][0] = 1;

        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=k;j++){
                
                // not taken 
                if(j<k){
                    t[i][j+1] = (t[i][j+1] + t[i][j])%mod;
                }
                if(j<k && i<m){
                    t[i+1][j+1] = (t[i+1][j+1] + t[i][j]*freq[target[i]-'a'][j])%mod;
                }
            }
        }
        return t[m][k];
    }
};
