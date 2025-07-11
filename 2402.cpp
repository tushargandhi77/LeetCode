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

// Optimul

class Solution {
public:
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings),end(meetings));

        priority_queue<P,vector<P>,greater<P>> usedRooms;
        priority_queue<int,vector<int>,greater<int>> availableRooms;

        vector<int> roomusedcount(n,0);

        for(int i = 0;i<n;i++){
            availableRooms.push(i);
        }

        for(auto& meet: meetings){
            int start = meet[0];
            int end = meet[1];

            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end,room});
                roomusedcount[room]++;
            }
            else{
                // no room available
                int room = usedRooms.top().second;
                long long endtime = usedRooms.top().first;

                usedRooms.pop();

                usedRooms.push({endtime+(end-start),room});
                roomusedcount[room]++;
            }
        }

        int maxused = 0;
        int room = -1;

        for(int i = 0;i<n;i++){
            if(maxused < roomusedcount[i]){
                maxused = roomusedcount[i];
                room = i;
            }
        }

        return room;
    }
};
