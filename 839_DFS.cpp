class Solution {
public:
    bool issimilar(string& s1,string& s2){
        int diff = 0;
        if(s1.length() != s2.length()) return false;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] != s2[i]) diff++;
        }

        return diff == 0 || diff == 2;
    }

    void DFS(int curr,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        visited[curr] = true;

        for(int& v: adj[curr]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>> adj;
        int n = strs.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(issimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n,false);
        int result = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                DFS(i,adj,visited);
                result++;
            }
        }

        return result;
    }
};
