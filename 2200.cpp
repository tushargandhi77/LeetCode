class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){

                if(!st.count(i) && abs(i-j)<=k && nums[j] == key){
                    result.push_back(i);
                    st.insert(i);
                }
            }
        }

        return result;
    }
};
