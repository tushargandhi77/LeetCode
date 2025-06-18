class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        vector<vector<int>> result;

        int count = 0;
        vector<int> store;
        for(int i = 0;i<nums.size();i++){
            store.push_back(nums[i]);
            count++;
            if(count == 3){
                if((store[1]-store[0])>k) return {};
                if((store[2]-store[0])>k) return {};
                if((store[2]-store[1])>k) return {};
                result.push_back(store);
                count = 0;
                store = vector<int>();
            }
        }
        return result;
    }
};
