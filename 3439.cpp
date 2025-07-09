class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);


        for(int i = 1;i<n;i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }

        freeTime.push_back(eventTime-endTime[n-1]);


        // sliding window

        int i = 0;
        int j = 0;

        int sum = 0;
        int max_ans = INT_MIN;
        while(j < freeTime.size()){
            sum += freeTime[j];

            if((j-i+1) > (k+1)){
                sum -= freeTime[i];
                i++;
            }
            max_ans = max(max_ans,sum);
            j++;
        }

        return max_ans;
    }
};
