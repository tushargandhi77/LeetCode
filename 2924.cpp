class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for(auto& vec: edges){
            int u = vec[0];
            int v = vec[1];

            indegree[v]++;
        }
        int count = 0;
        int result = 0;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                result = i;
                count++;
            }
        }
        return count == 1 ? result : -1;
    }
};
