// LIS Varient
// Optimul

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;

        int result = INT_MIN;

        for(int& num: arr){
            int prev_num = num - difference;

            if(mp.find(prev_num) != mp.end()){
                mp[num] = 1 + mp[prev_num];
            }
            else{
                mp[num] = 1;
            }

            result = max(result,mp[num]);
        }

        return result;
    }
};


// TLE 

class Solution {
public:
    int t[100001];
    int solve(int idx,vector<int>& arr, int difference){
        if(idx >= arr.size()) return 0;

        if(t[idx] != -1) return t[idx];

        int ans = 0;
        for(int i = idx+1;i<arr.size();i++){
            if((arr[i] - arr[idx]) == difference){
                ans = max(ans, 1 + solve(i,arr,difference));
            }
        }

        return  t[idx] = ans;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        memset(t,-1,sizeof(t));

        int result = INT_MIN;
        for(int i = 0;i<n;i++){
            result = max(result,1 + solve(i,arr,difference));
        }

        return result == INT_MIN ? 0 : result;
    }
};

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
