class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));

        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto & vec: intervals){
            int start = vec[0];
            int end  = vec[1];

            if(!pq.empty() && start > pq.top()){
                pq.pop();
            }

            pq.push(end);
        }
        return pq.size();
    }
};
