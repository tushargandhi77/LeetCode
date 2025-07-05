// Dynamic Programming :- Recursion + Memo

class Solution {
public:
    int t[1001][2001];
    int solve(int idx,vector<vector<int>>& piles,int k){
        if(k < 0) return 0;
        if(idx  >= piles.size()) return 0;

        if(t[idx][k] != -1) return t[idx][k];

        int not_taken = solve(idx+1,piles,k);

        int taken = INT_MIN,sum = 0;
        for(int j = 0; j<min((int)piles[idx].size(),k);j++){
            sum += piles[idx][j];

            taken = max(taken,sum + solve(idx+1,piles,k-(j+1)));
        }

        return t[idx][k] = max(taken,not_taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,piles,k);
    }
};


// Bottom Up

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<vector<int>> t(n+1,vector<int>(k+1,0));

        for(int i = 1;i<=n;i++){
            for(int coins = 0;coins<=k;coins++){
                int sum = 0;

                for(int curr = 0;curr<=min((int)piles[i-1].size(),coins);curr++){
                    if(curr > 0){
                        sum += piles[i-1][curr-1];
                    }

                    t[i][coins] = max(t[i][coins],sum + t[i-1][coins - curr]);
                }
            }
        }

        return t[n][k];
    }
};
