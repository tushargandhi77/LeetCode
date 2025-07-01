// Memo
class Solution {
public:
    int t[501][501];
    int solve(int idx,int time,vector<int>& satisfaction){
        if(idx >= satisfaction.size()) return 0;

        if(t[idx][time] != -1) return t[idx][time];

        int take = satisfaction[idx]*time + solve(idx+1,time+1,satisfaction);

        int not_take = solve(idx+1,time,satisfaction);

        return t[idx][time] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        memset(t,-1,sizeof(t));
        return solve(0,1,satisfaction);
    }
};


// BU

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(begin(satisfaction),end(satisfaction));

        vector<vector<long long>> t(n,vector<long long>(n+1,INT_MIN));

        for(int i = 0;i<n;i++){
            t[i][0] = 0;
        }

        t[0][1] = satisfaction[0];

        for(int i = 1;i<n;i++){
            for(int time=1;time<=n;time++){
                long long include = satisfaction[i]*time + t[i-1][time-1];

                long long exclude = t[i-1][time];

                t[i][time] = max(include,exclude);
            }
        }

        return *max_element(begin(t[n-1]),end(t[n-1]));

    }
};
