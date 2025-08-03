class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> fruitsIdx(n);
        vector<int> prefixSum(n);

        for(int i = 0;i<n;i++){
            fruitsIdx[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i-1] : 0);
        }

        int maxFruits = 0;

        for(int d = 0;d <= k/2;d++){
            
            int i = startPos - d;
            int j = startPos + (k - 2 * d);

            int left = lower_bound(begin(fruitsIdx),end(fruitsIdx),i) - begin(fruitsIdx);
            int right = upper_bound(begin(fruitsIdx),end(fruitsIdx),j) - begin(fruitsIdx) - 1;

            if(left <= right){
                int result = prefixSum[right] - (left > 0 ? prefixSum[left-1]: 0);
                maxFruits = max(maxFruits,result);
            }

            i = startPos - (k - 2 * d);
            j = startPos + d;

            left = lower_bound(begin(fruitsIdx),end(fruitsIdx),i) - begin(fruitsIdx);
            right = upper_bound(begin(fruitsIdx),end(fruitsIdx),j) - begin(fruitsIdx) - 1;

            if(left <= right){
                int result = prefixSum[right] - (left > 0 ? prefixSum[left-1]: 0);
                maxFruits = max(maxFruits,result);
            }

        }

        return maxFruits;
    }
};
