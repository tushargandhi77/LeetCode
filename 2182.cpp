class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";

        vector<int> count(26,0);

        for(char& c:s){
            count[c-'a']++;
        }

        int i = 25;

        while(i>=0){
            if(count[i]==0){
                i--;
                continue;
            }

            int freq = min(count[i],repeatLimit);
            char ch = 'a' + i;
            result.append(freq,ch);
            count[i] -= freq;

            if(count[i] > 0){
                int j = i-1;

                while(j>=0 && count[j] == 0){
                    j--;

                }
                if(j<0) break;

                result.push_back('a'+j);
                count[j]--;
            }

        }
        return result;
    }
};
