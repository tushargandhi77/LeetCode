class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int result = 0;

        vector<string> vec;
        unordered_map<string,int> mp;

        for(auto& v : matrix){

            string s1 = "";
            string s2 = "";
            for(int i = 0;i<v.size();i++){
                s1 +=  to_string(v[i]);
                s2 += to_string(1-v[i]);
            }
            vec.push_back(s1);
            vec.push_back(s2);
        }

        for(auto& s: vec){
            mp[s]++;
        }
        for(auto& it: mp){
            if(it.second > result){
                result = it.second;
            }
        }
        return result;
    }
};
