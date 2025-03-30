class Solution {
public:
    int n;
    int t[1001][1001];
    bool ispred(string& s1,string& s2){
        int M = s1.length();
        int N = s2.length();

        if(M >= N || N-M != 1){
            return false;
        }
        int i = 0,j = 0;
        while(i < M && j < N){
            if(s1[i] == s2[j]) i++;
            j++;
        }
    
        return i == M;
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        auto lambda = [&](string& s1,string& s2){
            return s1.length() < s2.length();
        };
        sort(begin(words),end(words),lambda);

        vector<int> t(n,1);

        int maxL = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(ispred(words[j],words[i])){
                    t[i] = max(t[i],t[j]+1);
                    maxL = max(maxL,t[i]);
                }
            }
        }
        return maxL;
    }
};
