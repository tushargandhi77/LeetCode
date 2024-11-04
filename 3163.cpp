class Solution {
public:
    string compressedString(string word) {
        
        int n = word.length();
        int i = 0;
        int j = 0;
        string result = "";
        while(i < n){
            while(word[i] == word[j] && j < n) j++;    
            int count = j-i;
            int div = count / 9;
            int rem = count % 9;

            while(div--){
                result += to_string(9) + word[i];
            }
            
            if(rem != 0) result += to_string(rem) + word[i];

            i = j;
        }
        return result;
    }
};
