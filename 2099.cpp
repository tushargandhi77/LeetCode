// Priority Queue

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res(n,1e9);

        while(!pq.empty()){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            res[idx] = num;
        }

        vector<int> result;

        for(int i = 0;i<n;i++){
            if(res[i] != 1e9){
                result.push_back(res[i]);
            }
        }

        return result;

    }
};

// Sorting

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);

        for(int i = 0;i<n;i++){
            arr[i] = {nums[i],i};
        }

        sort(begin(arr),end(arr));

        vector<int> result(n,1e9);

        for(int i = n-k;i<n;i++){
            int idx = arr[i].second;
            int val = arr[i].first;

            result[idx] = val;
        }

        vector<int> res;

        for(int i = 0;i<n;i++){
            if(result[i] != 1e9){
                res.push_back(result[i]);
            }
        }

        return res;
    }
};

// BAcktracking

class Solution {
public:

    bool ismax(vector<int>& result,vector<int>& curr){
        if(result.empty()) return true;

        int result_sum = accumulate(begin(result),end(result),0);
        int curr_sum = accumulate(begin(curr),end(curr),0);

        return curr_sum > result_sum;
    }
    void Backtracking(int idx,int k,vector<int>& nums,vector<int>& curr,vector<int>& result){
        if(idx > nums.size()) return;

        if(curr.size() == k && ismax(result,curr)){
            result = curr;
        }

        for(int i = idx;i<nums.size();i++){

            // Do
            curr.push_back(nums[i]);

            // Explore
            Backtracking(i+1,k,nums,curr,result);

            // Undo
            curr.pop_back();
        }
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> curr;
        vector<int> result;

        Backtracking(0,k,nums,curr,result);

        return result;
    }
};
