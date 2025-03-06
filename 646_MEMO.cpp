class Solution {
public:
    int n;
    int t[1001][1001];
    int solve(int idx,int prev,vector<vector<int>>& pairs){
        if(idx >= n) return 0;

        if(t[idx][prev+1] != -1) return t[idx][prev+1];

        int take = 0;
        if(prev == -1 || pairs[prev][1] < pairs[idx][0]){
            take = 1 + solve(idx+1,idx,pairs);
        }

        int skip = solve(idx+1,prev,pairs);

        return t[idx][prev+1] = max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        n = pairs.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,pairs);
    }
};
