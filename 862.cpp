class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;
        vector<long long> cummsum(n);

        int j = 0;
        int result = INT_MAX;
        while(j < n){
            if(j == 0){
                cummsum[j] = nums[j];
            }
            else{
                cummsum[j] = cummsum[j-1] + nums[j];
                
            }

            if(cummsum[j] >= k) result = min(result,j+1);

            while(!deq.empty() && (cummsum[j] - cummsum[deq.front()])>=k){
                result = min(result,j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cummsum[j] <= cummsum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
    return result == INT_MAX ? -1 : result;
    }
};
