// Recursion + MEMO

class Solution {
public:
    int t[500001];
    int solve(int idx,vector<int>& stone){
        if(idx >= stone.size()){
            return 0;
        }

        if(t[idx] != -1) return t[idx];

        int result = INT_MIN;

        result = max(result,stone[idx] - solve(idx+1,stone));

        if(idx+1 < stone.size()){
        result = max(result,stone[idx] + stone[idx+1] - solve(idx+2,stone));
        }

        if(idx+2 < stone.size()){
        result = max(result,stone[idx] + stone[idx+1] + stone[idx+2] - solve(idx+3,stone));
        }

        return t[idx] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(t,-1,sizeof(t));

        int result = solve(0,stoneValue);
        
        return result == 0 ? "Tie" : (result > 0 ? "Alice" : "Bob");
    }
};

// Bottom Up

class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int> t(n+1);

        for(int i = n-1;i>=0;i--){
            t[i] = stone[i] - t[i+1];

            if(i+1 < n){
                t[i] = max(t[i],stone[i] + stone[i+1] - t[i+2]);
            }

            if(i+2 < n){
                t[i] = max(t[i], stone[i] + stone[i+1] + stone[i+2] - t[i+3]);
            }

        }

        return t[0] == 0 ? "Tie" : (t[0] > 0 ? "Alice" : "Bob");
    }
};
