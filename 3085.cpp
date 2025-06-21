class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(char& ch: word){
            freq[ch-'a']++;
        }

        int result = INT_MAX;

        for(int i = 0;i<26;i++){
            int maxDelete = 0;
            for(int j = 0;j<26;j++){
                if(i == j) continue;

                if(freq[j] < freq[i]) maxDelete += freq[j];

                else if((freq[j]-freq[i]) > k){
                    maxDelete += abs(freq[j] - freq[i] - k);
                }
            }
            result = min(result,maxDelete);
        }

        return result;
    }
};
