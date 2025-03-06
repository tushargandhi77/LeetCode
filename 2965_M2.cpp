class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;

        int n = grid.size();
        long long N = n*n;

        long long sum = (N*(N+1))/2;
        long long sqsum = (N*(N+1)*(2*N+1))/6;

        long long gridsum = 0;
        long long gridsqsum = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                gridsum += grid[i][j];
                gridsqsum += grid[i][j]*grid[i][j];
            }
        }

        int sqdiff = gridsqsum - sqsum;
        int diff = gridsum - sum;

        int a = (sqdiff/diff + diff)/2;
        int b = (sqdiff/diff - diff)/2;

        return {a,b};
    }
};
