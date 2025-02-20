class Solution {
public:
    void solve(int idx,string& curr,unordered_set<string>& st,int n,string& result){
        if(idx >= n){
            if(!st.count(curr)){
                result = curr;
                return;
            }
            return;
        }

        curr.push_back('1');
        solve(idx+1,curr,st,n,result);
        curr.pop_back();

        curr.push_back('0');
        solve(idx+1,curr,st,n,result);
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> st;

        for(string& s: nums){
            st.insert(s);
        }

        string result = "";
        string curr = "";
        solve(0,curr,st,n,result);    
        return result;
    }
};
