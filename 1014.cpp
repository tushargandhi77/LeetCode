class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> left_max(n,INT_MIN);
        int maxi = values[0];
        
        for(int i = 0;i<n;i++){
            maxi = (values[i] + i) > maxi ? (values[i]+i) : maxi;
            left_max[i] = max(maxi,left_max[i]);
        }
        
        int max_score = INT_MIN;

        for(int j = 1;j<n;j++){
            int value = left_max[j-1] + (values[j]-j);
            max_score = max(max_score,value);
        }
        return max_score;
    }
};
