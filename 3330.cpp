class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        int n = word.length();

        int i = 0;

        while(i<n){
            int j = i+1;
            while(j < n && word[i] == word[j]){
                j++;
            }
            if(j != i+1){
                result += (j-1-i);
            }
            i = j;
        }

        return result;
    }
};
