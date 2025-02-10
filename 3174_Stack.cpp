class Solution {
public:
    bool isdigit(char ch){
        if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0'){
            return true;
        }
        return false;
    }
    string clearDigits(string s) {
        string result = "";

        int n = s.length();

        stack<char> st;

        for(auto& ch: s){
            if(!isdigit(ch)){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
