class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negativecount = 0;
        int positivecount = 0;

        for(int& num: nums){
            if(num < 0){
                negativecount++;
            }
            else if(num > 0){
                positivecount++;
            }
        }

        return max(negativecount,positivecount);
    }
};
