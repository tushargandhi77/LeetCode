class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());

        unordered_set<string> visited;

        queue<string> que;
        que.push(start);
        visited.insert(start);

        int level = 0;
        while(!que.empty()){
            int n = que.size();

            while(n--){
                string s = que.front();
                que.pop();
                if(s == end) return level;
                for(const char& c: "ACGT"){
                    for(int i = 0;i<8;i++){
                        char ch = s[i];
                        s[i] = c;
                        if(visited.find(s) == visited.end() && bankset.find(s) != bankset.end()){
                            que.push(s);
                            visited.insert(s);
                        }
                        s[i] = ch;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
