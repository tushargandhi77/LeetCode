class Solution {
public:
    int result;
    void solve(vector<int>& vec){
        result++;

        for(int i = 0;i<26;i++){
            if(vec[i] == 0) continue;

            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        result = 0;
        vector<int> vec(26,0);
        for(char& ch: tiles){
            vec[ch-'A']++;
        }

        solve(vec);

        return result-1;
    }
};
