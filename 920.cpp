class Solution {
public:
    int N,G,K;
    const int MOD = 1e9 + 7;
    long t[101][101];
    int solve(int current_count,int current_unique){
        if(current_count == G){
            if(current_unique == N) return 1;

            return 0;
        }

        if(t[current_count][current_unique] != -1) return t[current_count][current_unique];

        long result = 0;

        // option1 take unique
        if(current_unique < N){
            result += (long)(N-current_unique) * solve(current_count+1,current_unique+1);
        }

        // option2 take non unique
        if(current_unique > K){
            result += (long)(current_unique - K) * solve(current_count+1,current_unique);
        }

        return t[current_count][current_unique] = result % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        N = n;
        G = goal;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0);
    }
};
