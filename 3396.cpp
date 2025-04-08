class Solution {
public:
    int n;
    bool check(int idx,vector<int>& nums){
        unordered_set<int> st;
        for(int i = idx;i<n;i++){
            if(st.count(nums[i])) return false;
            st.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        for(int i = 0;i<n;i+=3){
            if(check(i,nums)){
                return result;
            }
            result++;
        }
        return result;
    }
};
