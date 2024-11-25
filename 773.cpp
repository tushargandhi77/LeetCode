class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        for(int i = 0;i<2;i++){
            for(int j = 0;j<3;j++){
                start += to_string(board[i][j]);
            }
        }
        string end = "123450";

        unordered_map<int,vector<int>> mp;
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {4,2};
        unordered_set<string> visited;

        queue<string> que;

        que.push(start);
        visited.insert(start);

        int level = 0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == end) return level;

                int zeroidx = curr.find('0');

                for(int& idx : mp[zeroidx]){
                    string cpy = curr;
                    swap(cpy[zeroidx],cpy[idx]);

                    if(!visited.count(cpy)){
                        visited.insert(cpy);
                        que.push(cpy);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
