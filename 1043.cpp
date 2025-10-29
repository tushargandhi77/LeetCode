class Solution {
public:
    int n;
    int t[501];
    int solve(int idx,vector<int>& arr,int k){
        if(idx >= n) return 0;

        if(t[idx] != -1) return t[idx];

        int result = 0;
        int maxE = arr[idx];

        for(int i = idx;i<min(idx+k,n);i++){
            maxE = max(maxE,arr[i]);
            result = max(result,maxE*(i-idx+1) + solve(i+1,arr,k));
        } 

        return t[idx] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t,-1,sizeof(t));
        return solve(0,arr,k);
    }
};

class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> t(n+1,0);

        for(int i = 1;i<=n;i++){
            int currMax = -1;
            for(int j = 1;j<=k&&(i-j) >= 0 ;j++){
                currMax = max(currMax,arr[i-j]);
                t[i] = max(t[i],currMax*j + t[i-j]);
            }
        }

        return t[n];
    }
};
