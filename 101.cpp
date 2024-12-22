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
    bool solve(TreeNode* L,TreeNode* R){
        if(L == NULL && R == NULL) return true;

        if(L == NULL || R == NULL) return false;

        if(L->val != R->val) return false;

        bool l = solve(L->left,R->right);
        bool r = solve(L->right,R->left);
        return l && r; 
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};
