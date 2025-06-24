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

// Method 2 optimul

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;

        int n = nums.size();


        for(int j = 0;j<n;j++){
            if(nums[j] == key){
                int start = max(0,j-k);
                int end = min(j+k,n-1);

                if(!result.empty() && result.back() >= start){
                    start = result.back() + 1;
                }

                for(int i = start;i<=end;i++){
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};
