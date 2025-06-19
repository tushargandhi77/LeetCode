class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordlist(begin(wordList),end(wordList));
        unordered_set<string> visited;

        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);

        int level = 1;

        while(!que.empty()){
            int N = que.size();
            while(N--){
                string curr = que.front();
                que.pop();

                if(curr == endWord) return level;

                for(int i = 0;i<curr.length();i++){
                    for(char ch = 'a';ch<='z';ch++){
                        char old = curr[i];

                        curr[i] = ch;
                        if(!visited.count(curr) && wordlist.count(curr)){
                            que.push(curr);
                            visited.insert(curr);
                        }
                        curr[i] = old;
                    }
                }
            }
            level++;
        }

        return 0;

    }
};
