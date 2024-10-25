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
    int DFS(TreeNode* root){
        if(!root) return 0;
        int lsum = DFS(root->left);
        int rsum = DFS(root->right);

        if(root->left == NULL && root->right == NULL) return 1;

        return lsum + rsum + 1;
    }
    int countNodes(TreeNode* root) {
        return DFS(root);
    }
};
