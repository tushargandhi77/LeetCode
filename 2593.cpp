class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
        }

        vector<bool> visited(n,false);
        long long score = 0;

        while(!pq.empty()){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(!visited[idx]){
                score += val;

                visited[idx] = true;

                if(idx == 0){
                    visited[idx+1] = true;
                }
                else if(idx == n-1){
                    visited[idx-1] = true;
                }
                else{
                    visited[idx-1] = true;
                    visited[idx+1] = true;
                }
            }
        }
        return score;
    }
};
