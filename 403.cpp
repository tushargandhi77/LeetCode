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


class Solution {
public:
    int maxStone;
    unordered_set<int> st;
    unordered_map<string,bool> mp;
    bool solve(int curr_stone,int jump){
        if(curr_stone == maxStone) return true;

        string key = to_string(curr_stone) + "_" + to_string(jump);

        if(mp.count(key)) return mp[key];

        bool result = false;

        for(int next_jump = jump-1;next_jump <= jump+1;next_jump++){
            if(next_jump > 0){
                int next_stone = curr_stone + next_jump;

                if(st.count(next_stone)){
                    result = result | solve(next_stone,next_jump);
                }
            }
        }

        return mp[key] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[1] != 1) return false;

        maxStone = stones[n-1];

        for(int& num: stones){
            st.insert(num);
        }

        return solve(0,0);
    }
};
