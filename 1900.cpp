class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer;
        int right = secondPlayer;

        if(left + right == n+1){
            return {1,1};
        }

        if(left > n-right+1){
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound = n;
        int maxRound = 1;
        int nextRoundPlayerCount = (n+1)/2;

        if(right <= nextRoundPlayerCount){ // case 1
            int countLeft = left - 1;
            int midCount = right - left -1;

            for(int surviorsLeft = 0;surviorsLeft <= countLeft;surviorsLeft++){
                for(int survivorMid = 0;survivorMid<=midCount;survivorMid++){
                    int pos1 = surviorsLeft + 1;
                    int pos2 = pos1 + survivorMid + 1;
                    vector<int> tempResult = earliestAndLatest(nextRoundPlayerCount,pos1,pos2);

                    minRound = min(minRound,tempResult[0]+1);
                    maxRound = max(maxRound,tempResult[1]+1);
                }
            }
        }
        else{
            int fightRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightRight - left - 1;
            int remainMidCount = right - fightRight -1;

            for(int surviorsLeft = 0;surviorsLeft <= countLeft;surviorsLeft++){
                for(int survivorMid = 0;survivorMid<=midCount;survivorMid++){
                    int pos1 = surviorsLeft + 1;
                    int pos2 = pos1 + survivorMid + (remainMidCount+1)/2 + 1;
                    vector<int> tempResult = earliestAndLatest(nextRoundPlayerCount,pos1,pos2);

                    minRound = min(minRound,tempResult[0]+1);
                    maxRound = max(maxRound,tempResult[1]+1);
                }
            }
        }

        return {minRound,maxRound};
    }
};
