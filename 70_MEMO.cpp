class Solution {
public:
    int t[46];
    int solve(int start,int end){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }

        if(t[start] != -1) return t[start];

        return t[start] = solve(start+1,end) + solve(start+2,end);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};
