class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int c_5 = 0;
        int c_10 = 0;

        for(int num: bills){
            if(num == 5) c_5 ++;
            else if(num == 10 ){
                if(c_5 > 0){
                    c_5 --;
                    c_10 ++;
                }
                else{
                    return false;
                }
            }
            else if(c_5 > 0 && c_10 > 0){
                c_5 --;
                c_10 --;
            }
            else if( c_5 >= 3){
                c_5 -= 3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
