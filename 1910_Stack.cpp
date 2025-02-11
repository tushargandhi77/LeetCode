class Solution {
public:
    bool check(stack<char> st,string& part,int n){
        stack<char> tempst = st;
        for(int i = n-1;i>=0;i--){
            if(tempst.top() != part[i]) return false;

            tempst.pop();
        }

        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;

        int m = s.length();
        int n = part.length();

        for(int i = 0;i<m;i++){
            st.push(s[i]);

            if(st.size() >= n && check(st,part,n) == true){
                for(int j = 0;j<n;j++){
                    st.pop();
                }
            }
        }
        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
