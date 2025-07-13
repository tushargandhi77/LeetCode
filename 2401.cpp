class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int count = 0;
        for(int i = 0;i<players.size();i++){
            int val = players[i];

            int idx = lower_bound(begin(trainers),end(trainers),val) - begin(trainers);

            if(idx < trainers.size()){
                trainers[idx] = -1;
                count++;
            }


        }

        return count;
    }
};
