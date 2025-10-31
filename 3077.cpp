class Solution {
public:
    typedef long long ll;
    vector<vector<vector<ll>>> t;
    int n;
    ll solve(int i,ll k,bool start_now,const vector<int>& nums){
        if(k == 0) return 0;

        if(i >= n) return -1e18;

        if(t[i][k][start_now] != -1) return t[i][k][start_now];

        ll take = -1e18;
        ll not_take = -1e18;
        if(start_now == true){
            not_take = solve(i+1,k,true,nums);
        }

        if(k%2 != 0){
            take = solve(i+1,k,false,nums) + nums[i]*k;
            take = max(take,solve(i+1,k-1,true,nums) + nums[i]*k);
        }
        else{
            take = solve(i+1,k,false,nums) - nums[i]*k;
            take = max(take,solve(i+1,k-1,true,nums) - nums[i]*k);
        }

        return t[i][k][start_now] = max(take,not_take);
    }
    ll maximumStrength(const vector<int>& nums, int k) {
        n = nums.size();
        t.resize(nums.size()+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
        return solve(0,k,true,nums);
    }
};
