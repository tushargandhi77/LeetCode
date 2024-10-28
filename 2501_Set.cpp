class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));

        int maxstreak = 0;

        for(auto& num: nums){
            int streak = 0;
            while(st.find(num) != st.end()){
                streak += 1;
                if((long long)num*num > 10e5) break;
                num *= num;
            }
            maxstreak = max(maxstreak,streak);
        }
        return maxstreak < 2 ? -1 : maxstreak;
    }
};
