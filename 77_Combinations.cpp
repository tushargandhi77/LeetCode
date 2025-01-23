class Solution {
public:
    vector<vector<int>> result;
    int N;
    void solve(int start,int k,vector<int>& temp){
        if(k == 0){
            result.push_back(temp);
            return;
        }
        if(start > N) return;

        temp.push_back(start);
        solve(start+1,k-1,temp);
        temp.pop_back();

        solve(start+1,k,temp);
        
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        vector<int> temp;
        solve(1,k,temp);
        return result;
    }
};
