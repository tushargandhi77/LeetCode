class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        for(string& s:equations){
            if(s[1] == '='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(string& s:equations){
            if(s[1] == '!'){
                int p1 = find(s[0]-'a');
                int p2 = find(s[3]-'a');

                if(p1==p2) return false;
            }
        }
        return true;
    }
};
