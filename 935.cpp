// Memo

class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int M = 1e9+7;

    int t[10][5001];
    int solve(int cell,int n){
        if(n == 0) return 1;

        if(t[cell][n] != -1) return t[cell][n];

        int ans = 0;
        for(int nextcell: mp[cell]){
            ans =  (ans + solve(nextcell,n-1)%M)%M;
        }

        return t[cell][n] = ans;
    }
    int knightDialer(int n) {
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,9,3};
        mp[6] = {0,1,7};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {2,4};
        mp[0] = {4,6};

        memset(t,-1,sizeof(t));
        int result = 0;

        for(int cell = 0;cell<=9;cell++){
            result = (result + solve(cell,n-1)%M)%M;
        }

        return result;
    }
};
