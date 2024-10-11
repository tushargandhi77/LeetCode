class Solution {
public:
    typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<P,vector<P>,greater<P>> occupied;
        priority_queue<int,vector<int>,greater<int>> free;

        int targetFriendarrival = times[targetFriend][0];

        int chairNo = 0;

        sort(begin(times),end(times));

        for(int i = 0;i<n;i++){
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival){
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty()){
                occupied.push({depart,chairNo});
                if(arrival == targetFriendarrival) return chairNo;
                chairNo++;
            }
            else{
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendarrival) return leastChairAvailable;
                occupied.push({depart,leastChairAvailable});
            }
        }
        return -1;
    }
};
