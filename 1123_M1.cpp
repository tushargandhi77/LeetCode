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
    unordered_map<int,int> mp;
    int max_Depth = 0;
    void height(TreeNode* root,int depth){
        if(!root) return;

        mp[root->val] = depth;
        max_Depth = max(max_Depth,depth);

        height(root->left,depth+1);
        height(root->right,depth+1);
    }
    TreeNode* LCA(TreeNode* root){
        if(root == NULL || mp[root->val] == max_Depth){
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l && r) return root;

        if(l != NULL) return l;

        return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        height(root,0);
        return LCA(root);
    }
};
