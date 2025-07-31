// Method 1
class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int>& piles){
        if(i > j) return 0;

        if(i == j) return piles[i];

        if(t[i][j] != -1) return t[i][j];

        int take_i = piles[i] + min(solve(i+1,j-1,piles),solve(i+2,j,piles));

        int take_j = piles[j] + min(solve(i+1,j-1,piles),solve(i,j-2,piles));

        return t[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));

        int total_stones = accumulate(begin(piles),end(piles),0);

        int alice = solve(0,piles.size()-1,piles);

        int bob = total_stones - alice;

        return alice > bob;
    }
};

// Method 2 

class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int>& piles){
        if(i > j) return 0;
        
        if(i == j) return piles[i];

        if(t[i][j] != -1) return t[i][j];

        int take_i = piles[i] - solve(i+1,j,piles); // calculate the difference of score alice - bob
        int take_j = piles[j] - solve(i,j-1,piles);

        return t[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        return solve(0,piles.size()-1,piles) > 0;
    }
};
