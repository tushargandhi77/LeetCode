class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]] = i;
        }
        int res_idx = INT_MAX;

        for(int i = 0;i<m;i++){
            int idx_max = INT_MIN;
            for(int j = 0;j<n;j++){
                idx_max = max(idx_max,mp[mat[i][j]]);
            }
            res_idx = min(res_idx,idx_max);
        }

        for(int i = 0;i<n;i++){
            int idx_max = INT_MIN;
            for(int j = 0;j<m;j++){
                idx_max = max(idx_max,mp[mat[j][i]]);
            }
            res_idx = min(res_idx,idx_max);
        }
        return res_idx;
    }
};
