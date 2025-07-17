class Solution {
public:
    int t[1003][1003];
    int solve(int i,int diff,vector<int>& nums){
        if(i < 0) return 0;

        if(t[i][diff+501] != -1) return t[i][diff+501];

        int ans = 0;
        for(int k = i-1;k>=0;k--){
            if((nums[i]-nums[k])==diff){
                ans = max(ans,1 + solve(k,diff,nums));
            }
        }

        return t[i][diff+501] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        memset(t,-1,sizeof(t));

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int diff = nums[j] - nums[i];

                result = max(result,2 + solve(i,diff,nums));
            }
        }
        return result;
    }
};
