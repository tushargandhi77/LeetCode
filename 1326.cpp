// rec + memo
class Solution {
public:
    int N;
    
    map<pair<int,int>,int> mp;
    int solve(int idx,int maxEnd,vector<pair<int,int>>& range){
        if(idx >= range.size()){
            if(maxEnd >= N) return 0;

            return 1e9;
        }

        if(range[idx].first > maxEnd) return 1e9;

        if(mp.count({idx,maxEnd})) return mp[{idx,maxEnd}];

        int not_take = solve(idx+1,maxEnd,range);

        int take = 1 + solve(idx+1,max(range[idx].second,maxEnd),range);

        return mp[{idx,maxEnd}] = min(not_take,take);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> range;
        N = n;

        for(int i = 0;i<ranges.size();i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);

            range.push_back({start,end});
        }

        sort(begin(range),end(range));

        return solve(0,0,range) == 1e9 ? -1 : solve(0,0,range);
    }
};

// Greedy

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,0);

        for(int i = 0;i<ranges.size();i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);

            startEnd[start] = max(startEnd[start],end);
        }

        int taps = 0;
        int currEnd = 0;
        int maxEnd = 0;

        for(int i = 0;i<n+1;i++){
            if(i > maxEnd) return -1;

            if(i > currEnd){
                taps++;
                currEnd = maxEnd;
            }

            maxEnd = max(maxEnd,startEnd[i]);
        }

        return taps;
    }
};
