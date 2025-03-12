class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lambdap = [](int num){
            return num > 0;
        };
        auto lambdan = [](int num){
            return num < 0;
        };


        int P = count_if(begin(nums),end(nums),lambdap);
        int n = count_if(begin(nums),end(nums),lambdan);

        return max(P,n);
    }
};
