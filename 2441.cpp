class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> visited(1001,false);

        for(int& num: nums){
            if(num > 0){
                visited[num] = true;
            }
        }   
        int result = -1;
        for(int& num: nums){
            if(num < 0){
                if(visited[-1*num]){
                    result = max(result,-1*num);
                }
            }
        }

        return result;
    }
};
