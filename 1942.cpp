class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chair(n,-1);

        int indexarival = times[targetFriend][0];

        sort(begin(times),end(times));

        for(auto& vec:times){
            int arival = vec[0];
            int leave = vec[1];

            for(int i = 0;i<n;i++){
                if(chair[i] <= arival){
                    chair[i] = leave;

                    if(arival == indexarival){
                        return i;
                    }
                break;
                }
        }
        }
    return -1;
    }
};
