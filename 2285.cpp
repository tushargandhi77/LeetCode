class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n);

        for(auto& road: roads){
            int u = road[0];
            int v = road[1];

            indegree[u]++;
            indegree[v]++;
        }

        sort(indegree.begin(),indegree.end());

        long long answer = 0;
        long long val = 1;
        for(int i = 0;i<n;i++){
            answer += indegree[i] * val;
            val++;
        }

        return answer;
    }
};
