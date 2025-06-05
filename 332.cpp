class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> result;

    void dfs(string u){
        auto& edge = adj[u];

        while(!edge.empty()){
            string v = edge.top();
            edge.pop();
            dfs(v);
        }

        result.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t: tickets){
            adj[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(begin(result),end(result));
        return result;
    }
};
