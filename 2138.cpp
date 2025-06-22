class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        for(int i = 0;i<s.length();i+=k){
            string str = s.substr(i,k);
            if(str.length() < k){
                int diff = k - str.length();
                while(diff--){
                    str += fill;
                }
            }
            result.push_back(str);
        }

        return result;
    }
};
