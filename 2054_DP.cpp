class Solution {
public:
    int t[100001][3];
    int binarysearch(vector<vector<int>>& events,int endTime,int n){
        int l = 0;
        int r = n-1;

        int result = n;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(events[mid][0] > endTime){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& events,int i,int count,int n){
        if(count == 2 || i >= n){
            return 0;
        }
        if(t[i][count] != -1) return t[i][count];

        // take
        int nextvalid_idx = binarysearch(events,events[i][1],n);
        int take = events[i][2] + solve(events,nextvalid_idx,count+1,n);

        // not take
        int not_take = solve(events,i+1,count,n);

        return t[i][count] = max(not_take,take);

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events),end(events));
        memset(t,-1,sizeof(t));

        int count = 0;
        return solve(events,0,count,n);
    }
};
