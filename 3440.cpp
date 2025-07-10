class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);

        for(int i = 1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }

        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int n = freeTime.size();

        int max_result = INT_MIN;

        for(int i = 0;i<n;i++){
            max_result = max(freeTime[i],max_result);
        }

        for(int i = 1;i<n;i++){
            max_result = max(max_result,freeTime[i]+freeTime[i-1]);
        }

        // Case 1;
        vector<int> leftMax(n);
        leftMax[0] = 0;
        for(int i = 1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],freeTime[i-1]);
        }
        vector<int> rightMax(n);
        rightMax[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],freeTime[i+1]);
        }


        for(int i = 1;i<n;i++){
            int d = endTime[i-1] - startTime[i-1];

            if(d <= leftMax[i-1] || d <= rightMax[i]){
                max_result = max(max_result,freeTime[i]+freeTime[i-1]+d);
            }
        }

        return max_result;
    }
};
