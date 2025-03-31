class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;
        vector<int> weightPair(m);

        for(int i = 0;i<m;i++){
            weightPair[i] = weights[i] + weights[i+1];
        }
        sort(begin(weightPair),end(weightPair));

        long long minW = 0;
        long long maxW = 0;

        for(int i = 0;i<k-1;i++){
            minW += weightPair[i];
            maxW += weightPair[m-i-1];
        }

        return (maxW-minW);
    }
};
