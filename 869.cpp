// method 1
class Solution {
public:
    string getsorted(int n){
        string s = to_string(n);
        sort(begin(s),end(s));

        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = getsorted(n);

        for(int p = 0;p<=29;p++){
            if(s == getsorted(1 << p)) return true;
        }

        return false;
    }
};
