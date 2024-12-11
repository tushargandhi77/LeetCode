class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int,int>> intervals(n);

        for(int i = 0;i<n;i++){
            intervals[i] = {nums[i]-k,nums[i]+k};
        }
        sort(intervals.begin() , intervals.end());

        queue<int> que;
        int maxBeauty = INT_MIN;
        for(auto& interval: intervals){

            while(!que.empty() && que.front() < interval.first){
                que.pop();
            }

            que.push(interval.second);
            maxBeauty = max(maxBeauty,(int)que.size());
        }
        return maxBeauty;
    }
};
