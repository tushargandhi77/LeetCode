class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i= 0;i<n;i++){
            string time = timePoints[i];

            string hr = time.substr(0,2);
            string mn = time.substr(3);

            int hourint = stoi(hr);
            int minint = stoi(mn);

            minutes[i] = hourint*60 + minint;
        }
        sort(begin(minutes),end(minutes));

        int result = INT_MAX;
        for(int i = 1;i<n;i++){
            result = min(result,minutes[i]-minutes[i-1]);
        }
        return min(result,(24*60 - minutes[n-1] + minutes[0]));
    }
};
