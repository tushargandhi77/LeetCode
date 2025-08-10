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

// m2
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

// M 3
class Solution {
public:
    vector<int> getVectorCount(int n){
        vector<int> vec(10,0);

        while(n){
            vec[n%10]++;
            n /= 10;
        }

        return vec;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> input = getVectorCount(n);

        for(int p = 0;p<=29;p++){
            if(input == getVectorCount(1 << p)) return true;
        }

        return false;
    }
};


// M4 

class Solution {
public:
    int getVectorCount(int n){
       int num = 0;

        while(n){
            num += pow(10,n%10);
            n /= 10;
        }

        return num;
    }
    bool reorderedPowerOf2(int n) {
        int input = getVectorCount(n);

        for(int p = 0;p<=29;p++){
            if(input == getVectorCount(1 << p)) return true;
        }

        return false;
    }
};
