class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0;i<n;i++){
           pq.push({nums[i],i});
        }

        while(k--){
            int element = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            int new_ele = multiplier*element;
            pq.push({new_ele,idx});
        }

        vector<int> result(n);
        while(!pq.empty()){
            int element = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            result[idx] = element;
        }
        return result;
    }
};
