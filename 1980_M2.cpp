class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;

        for(auto& s: nums){
            st.insert(stoi(s,0,2)); // insert in decimal form
        }

        int n = nums.size();

        string result = "";

        for(int i = 0;i<=n;i++){
            if(st.find(i) == st.end()){
                result = bitset<16>(i).to_string();

                return result.substr(16-n);
            }
        }
        return "";
    }
};
