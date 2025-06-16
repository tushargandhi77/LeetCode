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
