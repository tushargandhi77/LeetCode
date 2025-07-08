class Solution {
public:
    int n;
    int calculateIdx(int i,vector<vector<int>>& events){
        int endtime = events[i][1];

        int idx = n;

        for(int j = i+1;j<n;j++){
            if(events[j][0] > endtime){
                idx = j;
                break;
            }
        }

        return idx;
    }
    int solve(int idx,int attend,vector<vector<int>>& events, int k,vector<vector<int>>& t){
        if(attend >= k) return 0;

        if(idx >= n) return 0;

        if(t[idx][attend] != -1) return t[idx][attend];

        int not_taken = solve(idx+1,attend,events,k,t);

        int newidx = calculateIdx(idx,events);
        int taken = events[idx][2] + solve(newidx,min(attend+1,k),events,k,t);

        return t[idx][attend] = max(not_taken,taken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events),end(events));

        vector<vector<int>> t(n+1,vector<int>(k+1,-1));

        return solve(0,0,events,k,t);
    }
};
