class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int,int>> nums(n);

        for(int i = 0;i<n;i++){
            nums[i] = {nums1[i],nums2[i]};
        }

        auto lambda = [&](auto& P1,auto& P2){
            return P1.second > P2.second;
        };

        sort(begin(nums),end(nums),lambda);

        long long ksum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i = 0;i<k;i++){
            ksum += nums[i].first;
            pq.push(nums[i].first);
        }

        long long result = ksum * nums[k-1].second;

        for(int i = k;i<n;i++){
            
            int minu = nums[i].second;

            int nums1_min = pq.top();
            pq.pop();

            ksum += (nums[i].first - nums1_min);
            pq.push(nums[i].first);

            result = max(result,(long long)(ksum*minu));
        }
        return result;
    }
};
