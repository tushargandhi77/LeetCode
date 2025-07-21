class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);

        for(auto& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back(b);
            indegree[b]++;
        }

        queue<int> que;

        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        unordered_map<int,unordered_set<int>> mp;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int& v: adj[node]){
                mp[v].insert(node); // v is the next node so node is previosu node and further node of nodes

                for(int prev: mp[node]){
                    mp[v].insert(prev); // that node previous node 
                }

                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        vector<bool> result;

        for(auto& query: queries){
            int src = query[0];
            int dst = query[1];

            if(mp[dst].find(src) != mp[dst].end()){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }

        return result;
       
    }
};
