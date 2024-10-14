class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>  pq;

        for(auto& num:nums){
            pq.push(num);
        }
        long long result = 0;
        while(k--){
            int top = pq.top();
            result+=(long)top;
            pq.pop();

            pq.push(ceil(top/3.0));
        }
        return result;
    }
};
