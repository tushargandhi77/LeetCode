class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int level = 0;

        queue<pair<int,int>> que;
        set<pair<int,int>> visited;

        for(int i = 0;i<n;i++){
            que.push({i,1<<i});
            visited.insert({i,1<<i});
        }

        while(!que.empty()){
            int N = que.size();
            while(N--){
                int node = que.front().first;
                int mask = que.front().second;
                que.pop();

                // if(mask == (pow(2,n)-1)) return level;
                if(mask == ((1 << n) - 1)) return level;

                for(int& newnode: graph[node]){
                    int newmask = mask | (1 << newnode);

                    if(!visited.count({newnode,newmask})){
                        que.push({newnode,newmask});
                        visited.insert({newnode,newmask});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
