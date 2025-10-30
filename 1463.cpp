class Solution {
public:
    int m,n;
    int t[71][71][71];
    int solve(int row,int c1,int c2,vector<vector<int>>& grid){
        
        if(row >= m) return 0;

        if(t[row][c1][c2] != -1) return t[row][c1][c2];

        int cherry = grid[row][c1];
        if(c1 != c2){
            cherry += grid[row][c2];
        }

        int ans = INT_MIN;

        for(int val1 = -1;val1<=1;val1++){
            for(int val2 = -1;val2<=1;val2++){
                int newrow = row + 1;
                int newc1 = c1 + val1;
                int newc2 = c2 + val2;

                if(newc1 >= 0 && newc1 < n && newc2 >= 0 && newc2 < n){
                    ans = max(ans,solve(newrow,newc1,newc2,grid));
                }
            }
        }

        return t[row][c1][c2] = cherry + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size(); 
        memset(t,-1,sizeof(t));

        return solve(0,0,n-1,grid);
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71][71] = {0};

        t[0][0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];

        for(int row = 1;row<m;row++){

            for(int c1 = 0;c1 <=min(n-1,row);c1++){

                for(int c2 = max(0,n-1-row);c2<n;c2++){

                    int lastrowmax = 0;

                    for(int col1 = max(0,c1-1);col1 <= min(c1+1,n-1);col1++){
                        for(int col2 = max(0,c2-1);col2 <= min(c2+1,n-1);col2++){
                            
                            lastrowmax = max(lastrowmax,t[row-1][col1][col2]);

                        }
                    }

                    if(c1 != c2){
                        t[row][c1][c2] = lastrowmax + grid[row][c1] + grid[row][c2];
                    }
                    else{
                        t[row][c1][c2] = lastrowmax + grid[row][c1];
                    }
                }
            }
        }

        int result = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                result = max(result,t[m-1][i][j]);
            }
        }

        return result;
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prev(71,vector<int>(71,0));

        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];

        for(int row = 1;row<m;row++){

            vector<vector<int>> curr(71,vector<int>(71,0));

            for(int c1 = 0;c1 <=min(n-1,row);c1++){

                for(int c2 = max(0,n-1-row);c2<n;c2++){

                    int lastrowmax = 0;

                    for(int col1 = max(0,c1-1);col1 <= min(c1+1,n-1);col1++){
                        for(int col2 = max(0,c2-1);col2 <= min(c2+1,n-1);col2++){
                            
                            lastrowmax = max(lastrowmax,prev[col1][col2]);

                        }
                    }

                    if(c1 != c2){
                        curr[c1][c2] = lastrowmax + grid[row][c1] + grid[row][c2];
                    }
                    else{
                        curr[c1][c2] = lastrowmax + grid[row][c1];
                    }
                }
            }

            prev = curr;
        }

        int result = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                result = max(result,prev[i][j]);
            }
        }

        return result;
    }
};
