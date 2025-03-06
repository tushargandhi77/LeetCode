class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;

        int n = grid.size();
        int N = n*n;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int a = 0;
        int b = 0;
        for(int i = 1;i<=N;i++){
            if(mp[i] == 0){
                b = i;
            }
            if(mp[i] == 2){
                a = i;
            }
        }

        return {a,b};
    }
};
