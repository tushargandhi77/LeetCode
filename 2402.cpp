/// BF

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings),end(meetings));

        vector<int> roomusedcount(n,0);
        vector<long long> lastusedtime(n,0);

        for(auto& meet: meetings){
            int start = meet[0];
            int end = meet[1];

            int found = false;

            int earlyroomIdx = 0;
            long long earlyroomtime = LLONG_MAX;

            for(int room = 0;room < n;room++){
                
                if(lastusedtime[room] <= start){
                    found = true;
                    lastusedtime[room] = end;
                    roomusedcount[room]++;
                    break;
                }

                if(lastusedtime[room] < earlyroomtime){
                    earlyroomtime = lastusedtime[room];
                    earlyroomIdx = room;
                }

            }

            if(!found){
                lastusedtime[earlyroomIdx] += (end - start);
                roomusedcount[earlyroomIdx]++;
            }
        }

        int resultroom = -1;
        int maxuse = 0;

        for(int room = 0;room<n;room++){
            if(roomusedcount[room] > maxuse){
                maxuse = roomusedcount[room];
                resultroom = room;
            }
        }

        return resultroom;
    }
};
