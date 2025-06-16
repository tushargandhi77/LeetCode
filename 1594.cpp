class Solution {
public:
    int m,n;
    int MOD = 1e9+7;
    typedef long long ll;
    vector<vector<pair<ll,ll>>> t;

    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
        if(i == m-1 && j == n-1){
            return {grid[i][j],grid[i][j]};
        }

        if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX)){
            return t[i][j];
        }

        ll maxval = LLONG_MIN;
        ll minval = LLONG_MAX;

        if(i+1 < m){
            auto [downmax,downmin] = solve(i+1,j,grid);
            maxval = max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
            minval = min({minval,grid[i][j]*downmax,grid[i][j]*downmin});
        }

        if(j+1 < n){
            auto [rightmax,rightmin] = solve(i,j+1,grid);
            maxval = max({maxval,grid[i][j]*rightmax,grid[i][j]*rightmin});
            minval = min({minval,grid[i][j]*rightmax,grid[i][j]*rightmin});
        }

        return t[i][j] = {maxval,minval};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        t = vector<vector<pair<ll,ll>>>(m+1,vector<pair<ll,ll>>(n+1,{LLONG_MIN,LLONG_MAX}));

        auto [MaxProd,MinProd] = solve(0,0,grid);

        return MaxProd < 0 ? -1 : MaxProd % MOD;    
    }
};


// Method 2 -> bottom UP

class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll,ll>>> t(m,vector<pair<ll,ll>>(n));

        t[0][0] = make_pair(grid[0][0],grid[0][0]);

        // BASE CASE
        for(int col=1;col<n;col++){
            t[0][col] = {grid[0][col]*t[0][col-1].first,grid[0][col]*t[0][col-1].second};
        }

        for(int row = 1;row<m;row++){
            t[row][0] = {grid[row][0]*t[row-1][0].first,grid[row][0]*t[row-1][0].second};
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                ll upmax = t[i-1][j].first;
                ll upmin = t[i-1][j].second;
                ll leftmax = t[i][j-1].first;
                ll leftmin = t[i][j-1].second;

                t[i][j].first = max({grid[i][j]*(long long)upmax,grid[i][j]*(long long)upmin,grid[i][j]*(long long)leftmax,grid[i][j]*(long long)leftmin});
                t[i][j].second = min({grid[i][j]*(long long)upmax,grid[i][j]*(long long)upmin,grid[i][j]*(long long)leftmax,grid[i][j]*(long long)leftmin});
            }
        }

        return t[m-1][n-1].first < 0 ? -1 : t[m-1][n-1].first % MOD;
    }
};
