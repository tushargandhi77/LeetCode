class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1,vector<int>(n+1,1e9));

        for(int i = 0;i<=n;i++){
            grid[i][i] = 0;
        }

        for(int i = 2;i<=n;i++){
            int u = i-1;
            int v = i;
            grid[u][v] = 1;
            grid[v][u] = 1;
        }

        grid[x][y] = 1;
        grid[y][x] = 1;

        // floyed warshell
        for(int via = 1;via<=n;via++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    grid[i][j] = min(grid[i][j],grid[i][via] + grid[via][j]);
                }
            }
        }

        vector<int> result(n);

        for(int k = 1;k<=n;k++){
            int count = 0;
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(i == j) continue;
                    if(grid[i][j] == k) count++;
                }
            }
            result[k-1] = count;
        }

        return result;
    }
};
