class Solution {
public:
    int n;
    int Q;
    bool checkWithDifference(vector<int>& nums,vector<vector<int>>& queries,int k){
        vector<int> diff(n,0);

        for(int i = 0;i<=k;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int x = queries[i][2];

            diff[start] += x;
            if(end+1 < n){
                diff[end+1] -= x;
            }
        }

        int cumsum = 0;
        for(int i = 0;i<n;i++){
            cumsum += diff[i];

            diff[i] = cumsum;

            if(nums[i] - diff[i] > 0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();
        
        auto lambda = [](int a){
            return a == 0;
        };

        if(all_of(nums.begin(),nums.end(),lambda)) return 0;
        int l = 0;
        int r  = Q - 1;

        int k = -1;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(checkWithDifference(nums,queries,mid) == true){
                k = mid + 1;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return k;
    }
};
