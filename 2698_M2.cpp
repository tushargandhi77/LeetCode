class Solution {
public:
    bool check(int sq,int currsum,int num){
        if(sq == 0){
            return currsum == num;
        }

        return check(sq/10,currsum + sq%10,num) || check(sq/100,currsum+sq%100,num) || check(sq/1000,currsum+sq%1000,num) || check(sq/10000,currsum + sq%10000,num);
    }
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1;num <= n;num++){
            int sq = num*num;
            
            if(check(sq,0,num)==true){
                punish += sq;
            }
        }
        return punish;
    }
};
