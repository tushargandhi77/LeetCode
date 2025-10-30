class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            mp[u]++;
            mp[v]++;
        }

        for(auto it: mp){
            if(it.second != 1) return it.first;
        }

        return -1;
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for(int edge1 : edges[0]){
            for(int edge2 : edges[1]){
                if(edge1 == edge2) return edge1;
            }
        }

        return -1;
    }
};
