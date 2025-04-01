class Solution {
public:
    long long t[100001];
    long long solve(int idx,vector<vector<int>>& questions){
        if(idx >= questions.size()) return 0;

        if(t[idx] != -1) return t[idx];

        int skip_value = questions[idx][1];
        long long take = (long long)questions[idx][0] + solve(idx+skip_value+1,questions);
        long long skip = (long long)solve(idx+1,questions);

        return t[idx] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(t,-1,sizeof(t));
        return solve(0,questions);
    }
};
