// Mehtod 1 :- Normal
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> child_to_parent;

        for(int i = 0;i<n;i++){
            int node = i;
            int leftc = leftChild[i];
            int rightc = rightChild[i];

            if(leftc != -1){
                adj[i].push_back(leftc);
                
                if(child_to_parent.find(leftc) != child_to_parent.end()) return false;

                child_to_parent[leftc] = i;
            }
            if(rightc != -1){
                adj[i].push_back(rightc);
                
                if(child_to_parent.find(rightc) != child_to_parent.end()) return false;

                child_to_parent[rightc] = i;
            }
        }
        int root =  -1;
        for(int i = 0;i<n;i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1) return false;
                root = i;
            }
        }
        if(root == -1) return false;

        int count = 0;
        queue<int> que;
        vector<bool> visited(n,false);
        que.push(root);
        count = 1;
        visited[root] = true;

        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int& v:adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    count++;
                    que.push(v);
                }
            }
        }
        return count == n;
    }
};

// Mehod 2 :- DSU

class Solution {
public:
    int components;
    vector<int> parent;

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int P,int c){
        if(find(c) != c) return false;

        if(find(P) == c) return false;

        int c_parent = find(c);
        int P_parent = find(P);

        parent[c_parent] = P_parent;

        components--;

        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        components = n;

        for(int i = 0;i<n;i++){
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1 && Union(i,leftC) == false) return false;

            if(rightC != -1 && Union(i,rightC) == false) return false; 
        }

        return components == 1;
    }
};
