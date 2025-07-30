class Solution {
public:
    int n;
    unordered_map<vector<bool>,int> mp;
    int solve(vector<int>& nums,vector<bool>& visited,int ops){

        if(mp.find(visited) != mp.end()) return mp[visited];

        int max_ans = 0;

        for(int i = 0;i<n-1;i++){
            if(visited[i] == true) continue;
            for(int j = i+1;j<n;j++){
                if(visited[j] == true) continue;

                visited[i] = true;
                visited[j] = true;

                int score = ops * __gcd(nums[i],nums[j]);

                score += solve(nums,visited,ops+1);

                visited[i] = false;
                visited[j] = false;

                max_ans = max(max_ans,score);
            }
        }
        return mp[visited] = max_ans;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n,false);
        return solve(nums,visited,1);
    }
};
