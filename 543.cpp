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
    int SUM(TreeNode* root){
        if(!root) return 0;

        return 1 + max(SUM(root->left),SUM(root->right));
    }
    int result = 0;
    void solve(TreeNode* root){
        if(!root) return;

        int LH = SUM(root->left);
        int RH = SUM(root->right);
        result = max(result,LH+RH);

        solve(root->left);
        solve(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return result;
    }
};
