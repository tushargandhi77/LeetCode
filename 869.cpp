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


class Solution {
public:
    unordered_set<string> st;

    void buildset(){
        for(int p = 0;p<=29;p++){
            string s = to_string(1 << p);
            sort(begin(s),end(s));
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            buildset();
        }

        string s = to_string(n);
        sort(begin(s),end(s));

        return st.count(s);
    }
};
