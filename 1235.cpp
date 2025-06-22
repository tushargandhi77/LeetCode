class Solution {
public:
    int n;
    int t[50001];
    int getIndex(vector<vector<int>>& arr,int l,int target){
        int result = n+1;

        int r = n-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(arr[mid][0] >= target){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
    int solve(int i,vector<vector<int>>& arr){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1) return t[i];

        int next = getIndex(arr,i+1,arr[i][1]);
        int take = arr[i][2] + solve(next,arr);

        int not_take = solve(i+1,arr);

        return t[i] = max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t,-1,sizeof(t));

        vector<vector<int>> arr(n,vector<int>(3));

        for(int i = 0;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(begin(arr),end(arr));

        return solve(0,arr);
    }
};
