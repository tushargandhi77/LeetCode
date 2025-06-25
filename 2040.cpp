

// Brute Force TLE

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        priority_queue<long long> pq;

        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                pq.push((long long)nums1[i]*nums2[j]);

                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
