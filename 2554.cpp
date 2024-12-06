class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;

        int sum = 0;

        unordered_set<int> st(begin(banned),end(banned));

        for(int i = 1 ;i <= n;i++){
            if(!st.count(i) && (sum + i) <= maxSum){
                count++;
                sum += i;
            }
        }

        return count;
    }
};
