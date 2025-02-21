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
class FindElements {
public:
    unordered_set<int> st;

    void BFS(TreeNode* root,int x){
        queue<TreeNode*> que;
        que.push(root);

        root->val = x;
        st.insert(x);

        while(!que.empty()){
            auto node = que.front();
            que.pop();

            int value = node->val;

            if(node->left){
                que.push(node->left);
                node->left->val = 2*value + 1;
                st.insert(2*value+1);
            }
            if(node->right){
                que.push(node->right);
                node->right->val = 2* value + 2;
                st.insert(2*value+2);
            }
        }
    }
    FindElements(TreeNode* root) {
        BFS(root,0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
