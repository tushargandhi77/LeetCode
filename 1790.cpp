class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first_idx = -1;
        int second_idx = -1;

        int n = s1.length();

        if(s1 == s2) return true;

        int count = 0;
        for(int i = 0;i<n;i++){
            if(s1[i] != s2[i]){
                count++;
                if(count > 2) return false;
                if(count == 1){
                    first_idx = i;
                }
                if(count == 2){
                    second_idx = i;
                }
            }
        }
        if(count < 2) return false;

        swap(s2[first_idx],s2[second_idx]);
        if(count == 2 && s1 == s2) return true;

        return false;
    }
};
