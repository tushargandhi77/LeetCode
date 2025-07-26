# define ALL(x) begin(x),end(x) 
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;

        vector<vector<int>> conflictingPoints(n+1);

        for(auto &a : conflictingPairs){
            int c = min(a[0],a[1]);
            int b = max(a[0],a[1]);
            conflictingPoints[b].push_back(c);
        }

        int maxConflict = 0;
        int secondMaxConflict = 0;

        vector<long long> extra(n+1,0);

        for(int end = 1;end <= n;end++){
            for(int& u : conflictingPoints[end]){
                if(u >= maxConflict){
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                }
                else if(u > secondMaxConflict){
                    secondMaxConflict = u;
                }

            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }

        return valid + *max_element(ALL(extra));

    }
};
