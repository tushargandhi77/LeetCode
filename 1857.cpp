class Solution {

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();

        unordered_map<int,vector<int>> adj;
        vector<vector<int>> t(N,vector<int>(26,0));
        vector<int> indegree(N,0);
        int countNode = 0;
        int answer = 0;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for(int i = 0;i<N;i++){
            if(indegree[i] == 0){
                que.push(i);
                t[i][colors[i]-'a'] = 1;
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            countNode++;

            answer = max(answer,t[u][colors[u]-'a']);

            for(int& v: adj[u]){
                for(int i = 0;i<26;i++){
                    t[v][i] = max(t[v][i],t[u][i] + (colors[v]-'a'==i));
                }
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                }
            }

        }

        if(countNode != N) return -1;

        return answer;

    }
};
