class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char& ch:s){
            if(!st.empty() && ch==']' && st.top() == '[') st.pop();

            if(ch=='[') st.push(ch);
        }

        int result = (st.size()+1)/2;
        return result;
    }
};
