class Solution {
public:
    int N,M,K;
    const int MOD = 1e9+7;
    int t[51][101][51];
    int solve(int idx,int max_number,int search_cost){
        if(idx >= N){
            if(search_cost == K) return 1;
            return 0;
        }

        if(t[idx][max_number][search_cost] != -1) return t[idx][max_number][search_cost];
        long long result = 0;
        for(int i = 1;i<=M;i++){
            if(i > max_number){
                result += (long long)(solve(idx+1,i,search_cost+1)%MOD);
            }
            else{
                result += (long long)(solve(idx+1,max_number,search_cost)%MOD);
            }
        }

        return t[idx][max_number][search_cost] = result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};
