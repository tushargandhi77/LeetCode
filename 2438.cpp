class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        vector<int> result;
        const int MOD = 1e9+7;

        for(int i = 0;i<32;i++){
            if((n & (1 << i)) != 0){
                power.push_back(1<<i);
            }
        }

        for(auto& query: queries){
            int start = query[0];
            int end = query[1];

            long ans = 1;
            for(int i = start;i<=end;i++){
                ans = (ans%MOD * power[i]%MOD)%MOD;
            }

            result.push_back(ans);
        }

        return result;
    }
};
