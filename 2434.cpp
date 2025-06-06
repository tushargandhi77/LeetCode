class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minRtoL(n);

        for(int i = n-1;i>=0;i--){
            if(i == n-1){
                minRtoL[i] = s[i];
            }
            else{
                minRtoL[i] = min(minRtoL[i+1],s[i]);
            }
        }

        string t = "";
        string paper = "";

        int i = 0;
        while(i < n){
            t.push_back(s[i]);

            char minchar = (i+1 < n) ? minRtoL[i+1] : s[i];

            while(!t.empty() && t.back() <= minchar){
                paper += t.back();
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
