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
    int result = 0;
    void solve(TreeNode* root,int val){
        if(!root) return;

        val = (val ^ (1<<root->val));
        if(root->left == NULL && root->right == NULL){
            if(__builtin_popcount(val) <= 1) result++;
        }
        solve(root->left,val);
        solve(root->right,val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int val = 0;
        solve(root,val);
        return result;
    }
};
