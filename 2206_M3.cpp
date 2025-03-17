class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> vec(501,true);

        for(int& x: nums){
            vec[x] = !vec[x];
        }

        for(int i = 0;i<501;i++){
            if(vec[i] == false) return false;
        }

        return true;
    }
};
