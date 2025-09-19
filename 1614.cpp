class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int result = 0;
        for(char& ch: s){
            if(ch == '('){
                st.push('(');
            }
            if(ch == ')'){
                int max_size = st.size();
                result = max(result,max_size);
                st.pop();
            }
        }

        return result;
    }
};
