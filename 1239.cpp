// Recusion 
class Solution {
public:
    int n;
    bool isdublicate(string& temp,string &s){
        unordered_set<char> st(begin(temp),end(temp));

        if(st.size() != temp.length()) return true;

        for(char& ch: s){
            if(st.count(ch)){
                return true;
            }
        }

        return false;
    }
    int solve(int idx,string temp,vector<string>& arr){
        if(idx >= n) return temp.length();

        int include = 0;
        int exclude = 0;

        if(!isdublicate(arr[idx],temp)){
            include = solve(idx+1,temp+arr[idx],arr);
        }

        exclude = solve(idx+1,temp,arr);

        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        n = arr.size();

        return solve(0,temp,arr);
    }
};


// DP Memoization

class Solution {
public:
    int n;

    unordered_map<string,int> mp;
    bool isdublicate(string& temp,string &s){
        unordered_set<char> st(begin(temp),end(temp));

        if(st.size() != temp.length()) return true;

        for(char& ch: s){
            if(st.count(ch)){
                return true;
            }
        }

        return false;
    }
    int solve(int idx,string temp,vector<string>& arr){
        if(idx >= n) return temp.length();

        int include = 0;
        int exclude = 0;

        string key = to_string(idx) + "_" + temp;

        if(mp.count(key)) return mp[key];

        if(!isdublicate(arr[idx],temp)){
            include = solve(idx+1,temp+arr[idx],arr);
        }

        exclude = solve(idx+1,temp,arr);

        return mp[key] = max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        n = arr.size();
        mp.clear();

        return solve(0,temp,arr);
    }
};
