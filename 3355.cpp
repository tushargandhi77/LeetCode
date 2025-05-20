class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffarr(n,0);

        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            diffarr[start] += 1;
            if(end+1 < n){
                diffarr[end+1] -= 1;
            }
        }

        // cumm sum
        for(int i = 1;i<n;i++){
            diffarr[i] += diffarr[i-1];
        }

        for(int i = 0;i<n;i++){
            if(diffarr[i] < nums[i]) return false;
        }
        return true;
    }
};
