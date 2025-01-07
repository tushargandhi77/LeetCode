class Solution {
public:
    vector<string> stringMatching(vector<string>& s) {
        vector<string> result;
        unordered_set<string> st;
        int n = s.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;

                if(s[i].find(s[j]) != string::npos && st.find(s[j]) == st.end()){
                    result.push_back(s[j]);
                    st.insert(s[j]);
                }
            }
        }
        return result;
    }
};
