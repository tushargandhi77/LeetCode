
class Solution {
public:
    bool checkHammingDist(string s1,string s2){
        int diff = 0;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> parent(n,-1);

        int longestsub = 1;
        int longestidx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=i-1;j++){
                if(groups[j] != groups[i] && words[i].length() == words[j].length() && checkHammingDist(words[i],words[j])){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        parent[i] = j;

                        if(longestsub < dp[i]){
                            longestsub = dp[i];
                            longestidx = i;
                        }
                    }
                }
            }
        }
        vector<string> result;
        while(longestidx != -1){
            result.push_back(words[longestidx]);
            longestidx =  parent[longestidx];
        }
        reverse(begin(result),end(result));
        return result;
    }
};
