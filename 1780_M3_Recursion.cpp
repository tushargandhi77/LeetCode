class Solution {
public:
    bool solve(int n ,int p){
        if(n == 0) return true;

        if(pow(3,p) > n) return false;

        bool take = solve(n-pow(3,p),p+1);

        bool not_take = solve(n,p+1);

        return take | not_take;
    }
    bool checkPowersOfThree(int n) {
        return solve(n,0);
    }
};
