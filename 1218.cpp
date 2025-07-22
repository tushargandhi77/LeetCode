// LIS Varient


// MLE
class Solution {
public:
    int solve(int prev_idx,int idx,vector<int>& arr, int difference,vector<vector<int>> t){
        if(idx >= arr.size()) return 0;

        if(t[idx][prev_idx+1] != -1) return t[idx][prev_idx+1];

        int take = 0;
        if(prev_idx == -1 || arr[idx] == arr[prev_idx]+difference){
            take = 1 + solve(idx,idx+1,arr,difference,t);
        }

        int skip = solve(prev_idx,idx+1,arr,difference,t);

        return t[idx][prev_idx+1] = max(take,skip);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));

        return solve(-1,0,arr,difference,t);
    }
};
