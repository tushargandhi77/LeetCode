class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0;i<s.length();i++){
            string newstr = s.substr(i)+s.substr(0,i);
            if(newstr == goal) return true;
        }
        return false;
    }
};
