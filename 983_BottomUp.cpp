class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days),end(days));
        int last_day = days.back();

        vector<int> t(last_day+1,0);

        t[0] = 0;

        for(int i = 1;i<=last_day;i++){
            if(st.find(i) == st.end()){
                t[i] = t[i-1];
                continue;
            }
            t[i] = INT_MAX;

            int take_1 = costs[0] + t[i-1];
            int take_7 = costs[1] + t[max(i-7,0)];
            int take_30 = costs[2] + t[max(i-30,0)];

            t[i] = min({take_1,take_7,take_30});
        }

        return t[last_day];
    }
};
