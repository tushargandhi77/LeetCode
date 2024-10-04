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
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        que.push(root);
        result = root->val;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                if(node->right){
                    result = node->right->val;
                    que.push(node->right);
                }
                if(node->left){
                    result = node->left->val;
                    que.push(node->left);
                }
                

            }
        }
        return result;
    }
};
