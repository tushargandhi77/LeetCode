class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(begin(deadends),end(deadends));

        if(visited.count("0000")) return -1;

        queue<string> que;
        que.push("0000");
        visited.insert("0000");

        int level = 0;

        while(!que.empty()){
            int N = que.size();
            while(N--){
                string curr = que.front();
                que.pop();

                if(curr == target) return level;

                for(int i = 0;i<4;i++){
                    char ch = curr[i];

                    char inc = (ch == '9' ? '0' : ch + 1);
                    curr[i] = inc;
                    if(!visited.count(curr)){
                        que.push(curr);
                        visited.insert(curr);
                    }

                    char dec = (ch == '0' ? '9' : ch - 1);
                    curr[i] = dec;
                    if(!visited.count(curr)){
                        que.push(curr);
                        visited.insert(curr);
                    }

                    curr[i] = ch;
                }
            }
            level++;
        }

        return -1;
    }
};
