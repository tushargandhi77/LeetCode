class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<char,int>,int> mp;

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(s[i] == s[j]){
                    mp[{s[i],(j-i+1)}] += 1;
                }
                else{
                    break;
                }
            }
        }
        int result = 0;
        for(auto& it: mp){
            int first = it.first.second;
            int num = it.second;
            if( num >= 3 && first > result){
                result = first;
            }
        }
        return result == 0 ? -1 : result;
    }
};
