class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n,0);
        vector<int> indexRowCount(m,0);

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    indexColCount[j]++;
                    indexRowCount[i]++;
                }
            }
        }

        int result = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && (indexColCount[j] >= 2 || indexRowCount[i] >= 2)){
                    result++;
                }
            }
        }
        return result;
    }
};
