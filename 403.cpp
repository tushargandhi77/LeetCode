class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int t[2001][2001];
    bool solve(int curr_stone_idx,int jump,vector<int>& stones){
        if(curr_stone_idx == n-1) return true;

        if(t[curr_stone_idx][jump] != -1) return t[curr_stone_idx][jump];

        bool result = false;

        for(int next_jump = jump-1;next_jump<=jump+1;next_jump++){
            if(next_jump > 0){
                int next_stone = stones[curr_stone_idx] + next_jump;

                if(mp.count(next_stone)){
                    result = result | solve(mp[next_stone],next_jump,stones);
                }
            }
        }

        return t[curr_stone_idx][jump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();

        if(stones[1] != 1) return false;

        memset(t,-1,sizeof(t));
        for(int i = 0;i<n;i++){
            mp[stones[i]] = i;
        }

        return solve(mp[0],0,stones);
    }
};
