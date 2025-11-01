class Solution {
public:
    int n,K;
    void solve(int idx,vector<int>& t,vector<int>& cookies,int& result){
        if(idx >= n){
            result = min(result,*max_element(begin(t),end(t)));
            return;
        }

        for(int i = 0;i<K;i++){
            t[i] += cookies[idx];

            solve(idx+1,t,cookies,result);
            
            
            t[i] -= cookies[idx];
        }

        
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int result = INT_MAX;
        vector<int> t(k,0);

        n = cookies.size();
        K = k;

        solve(0,t,cookies,result);

        return result;
    }
};
