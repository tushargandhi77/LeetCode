class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(auto& num : nums){
            pq.push(num);
        }
        int result = 0;
        while(!pq.empty() && pq.top() < k){
            int num1 = pq.top();
            pq.pop();
            if(!pq.empty()){
                int num2 = pq.top();
                pq.pop();

                long long number = 2*(long long)min(num1,num2) + (long long)max(num1,num2);
                pq.push(number);
                result++;
            }
        }
        return result;
    }
};
