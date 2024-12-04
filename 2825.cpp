class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        int n1 = str1.length();
        int n2 = str2.length();

        while(i < n1 && j < n2){
            if((str1[i]==str2[j]) || (str1[i]+1 == str2[j]) || (str1[i] == 'z' && str2[j] == 'a')){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j == n2;
    }
};
