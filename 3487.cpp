class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));

        int sum = 0;
        int negSum = INT_MIN;
        for(int num: st){
            if(num > 0){
                sum += num;
            }
            else{
                negSum = max(negSum,num);
            }
        }


        return sum == 0 ? negSum : sum;
    }
};
