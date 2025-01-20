class Solution {
public:
    int m,n;
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>> mp;
        m = mat.size();
        n = mat[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        int res_idx = -1;
        vector<int> countrow(m,0);
        vector<int> countcol(n,0);
        for(int i = 0;i<arr.size();i++){
            auto it = mp[arr[i]];

            int x = it.first;
            int y = it.second;
            mat[x][y] = -1;
            countrow[x]++;
            countcol[y]++;

            if(countrow[x] == n || countcol[y] == m){
                res_idx = i;
                break;
            }
        }
        return res_idx;
    }
};
