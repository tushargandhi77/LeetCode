
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
