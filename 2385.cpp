/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void make_graph(unordered_map<int,vector<int>>& adj,int parent,TreeNode* curr){
        if(!curr) return;

        if(parent != -1) adj[curr->val].push_back(parent);

        if(curr->left) adj[curr->val].push_back(curr->left->val);

        if(curr->right) adj[curr->val].push_back(curr->right->val);

        make_graph(adj,curr->val,curr->left);
        make_graph(adj,curr->val,curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;

        make_graph(adj,-1,root);
        int min = 0;

        queue<int> que;
        que.push(start);
        set<int> st;
        st.insert(start);

        while(!que.empty()){
            int n = que.size();
            while(n--){
                int curr = que.front();
                que.pop();

                for(int& nbr:adj[curr]){
                    if(st.find(nbr) == st.end()){
                        que.push(nbr);
                        st.insert(nbr);
                    }
                }
            }
            min++;
        }
        return min-1;
    }
};
