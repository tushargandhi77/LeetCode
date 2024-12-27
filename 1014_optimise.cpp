class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int maxi = values[0];

        int max_score = INT_MIN;

        for(int i = 1;i<n;i++){
            maxi = max(maxi,values[i-1]+(i-1));

            max_score = max(max_score, maxi + (values[i]-i));
        }

        return max_score;
    }
};
