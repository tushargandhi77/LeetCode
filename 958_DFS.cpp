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
    int count = 0;
    void countnode(TreeNode* root){
        if(!root) return;

        count++;
        countnode(root->left);
        countnode(root->right);
    }

    void  dfs(TreeNode* root,int i,bool& ans){
        if(!root) return;

        if(i > count){
            ans = false;
            return;
        }

        dfs(root->left,2*i,ans);
        dfs(root->right,2*i+1,ans);
    }

    bool isCompleteTree(TreeNode* root) {
        countnode(root);
        bool ans = true;
        dfs(root,1,ans);
        return ans;
    }
};
