class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        sort(begin(s1),end(s1));

        for(int i = 0;i<(s2.size()-s1.size())+1;i++){
            string check = s2.substr(i,s1.size());
            sort(begin(check),end(check));
            if(check==s1){
                return true;
            }
        }
        return false;

    }
};
