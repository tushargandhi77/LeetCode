class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));

        vector<int> t(n,1);
        vector<int> prev_idx(n,-1);

        int lst_chosen_index = 0;
        int maxL = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] %  nums[j] == 0){
                    if(t[i] < t[j]+1){
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }
                    if(t[i] >= maxL){
                        maxL = t[i];
                        lst_chosen_index = i;
                    }
                }
            }
        }
        vector<int> result;
        while(lst_chosen_index != -1){
            result.push_back(nums[lst_chosen_index]);
            lst_chosen_index = prev_idx[lst_chosen_index];
        }

        return result;
    }
};
