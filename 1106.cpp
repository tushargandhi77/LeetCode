
class Solution {
public:
    char solveOperator(vector<char>& values,char operators){
        if(operators == '!'){
            return values[0] == 't' ? 'f' : 't';
        }

        if(operators == '&'){
            for(char &ch: values){
                if(ch=='f'){
                    return 'f';
                }
            }
            return 't';
        }
        if(operators == '|'){
            for(char &ch:values){
                if(ch=='t'){
                    return 't';
                }
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(s[i] == ',') continue;

            if(s[i] == ')'){
                vector<char> values;

                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char operators = st.top();
                st.pop();

                st.push(solveOperator(values,operators));
            }
            else{
                st.push(s[i]);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
