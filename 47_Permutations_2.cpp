class Solution {
public:
    vector<vector<int>> result;
    int N;

    void solve(vector<int>& temp,unordered_map<int,int>& mp){
        if(temp.size() == N){
            result.push_back(temp);
            return;
        }

        for(auto& [num,count] : mp){
            if(count == 0) continue;

            temp.push_back(num);
            mp[num]--;

            solve(temp,mp);

            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<N;i++){
            mp[nums[i]]++;
        }
        vector<int> temp;
        solve(temp,mp);

        return result;
    }
};
