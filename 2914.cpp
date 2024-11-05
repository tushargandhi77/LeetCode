class Solution {
public:
    int minChanges(string s) {
        char ch = s[0];

        int count = 0;
        int changes = 0;

        for(int i = 0;i<s.length();i++){
            if(s[i] == ch){
                count++;
                continue;
            }

            if(count%2 == 0){
                count = 1;
            }
            else{
                count = 0;
                changes += 1;
            }
            ch = s[i];
        }
        return changes;
    }
};
