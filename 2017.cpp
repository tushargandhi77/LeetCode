class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstrowremsum = accumulate(begin(grid[0]),end(grid[0]),0LL);

        long long secondrowremsum = 0;

        long long minimized = LONG_LONG_MAX;

        for(int rowcol = 0; rowcol < grid[0].size() ;rowcol++){
            firstrowremsum -= grid[0][rowcol];

            long long maxi = max(firstrowremsum,secondrowremsum);

            minimized = min(minimized,maxi);

            secondrowremsum += grid[1][rowcol];
        }

        return minimized;
    }
};
