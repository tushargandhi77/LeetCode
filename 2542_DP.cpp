class Solution {
public:
    int K;
    int N;
    unordered_map<string,int> mp;
    long long solve(vector<int>& nums1,vector<int>& nums2,int i,int sum,int minu,int count){
        if(count == K){
            return sum*minu;
        }
        if(i >= N){
            return 0;
        }

        string key = to_string(i) + "_" + to_string(sum) + "_" + to_string(minu) + "_" + to_string(count);

        if(mp.find(key) != mp.end()){
            return mp[key];
        }

        long long take = solve(nums1,nums2,i+1,sum+nums1[i],min(minu,nums2[i]),count+1);
        long long not_take = solve(nums1,nums2,i+1,sum,minu,count);

        return mp[key] = max(take,not_take);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        N = nums1.size();
        K = k;
        mp.clear();
        return solve(nums1,nums2,0,0,INT_MAX,0);
    }
};
