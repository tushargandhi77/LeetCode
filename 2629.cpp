class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(auto& ch:s){
            if(!st.empty() && (ch == 'B') && (st.top() == 'A')){
                st.pop();
                continue;
            }
            else if(!st.empty() && (ch=='D') && (st.top() == 'C')){
                st.pop();
                continue;
            }

            st.push(ch);
        }
        return st.size();
    }
};
