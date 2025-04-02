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

     vector<int> parent;
     vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;

        return find(parent[x]);
    }

    void Union(int x,int y){
        if(find(x) == find(y)) return;

        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x] > rank[y]){
            parent[y_parent] = x_parent; 
        }
        else if(rank[y] > rank[x]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>> adj;
        int n = strs.size();
        int result = n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(issimilar(strs[i],strs[j]) && find(i) != find(j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    Union(i,j);
                    result--;
                }
            }
        }

        return result;


    }
};
