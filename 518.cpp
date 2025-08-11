class Solution {
public:
    int t[301][5002];
    int solve(int idx,int curramount,int amount,vector<int>& coins){
        if(curramount > amount) return 0;

        if(curramount == amount) return 1;

        if(t[idx][curramount] != -1) return t[idx][curramount];


        int result = 0;

        for(int i = idx;i<coins.size();i++){
            result += solve(i,min(curramount+coins[i],amount+1),amount,coins);
        }

        return t[idx][curramount] = result;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(0,0,amount,coins);
    }
};


class Solution {
public:
    int t[301][5002];
    int solve(int idx,int curramount,int amount,vector<int>& coins){
        if(curramount == amount) return 1;

        if(idx == coins.size()) return 0;

        if(curramount > amount) return 0;

        if(t[idx][curramount] != -1) return t[idx][curramount];

        int take = solve(idx,min(curramount+coins[idx],amount+1),amount,coins);

        int skip = solve(idx+1,curramount,amount,coins);

        return t[idx][curramount] = take+skip;
    }   
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(0,0,amount,coins);
    }
};
