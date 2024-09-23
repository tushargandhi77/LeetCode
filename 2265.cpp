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
    int findsum(TreeNode* root,int &count){
        if(!root) return 0;
        count++;
        int leftsum = findsum(root->left,count);
        int rightsum = findsum(root->right,count);
        return leftsum+rightsum+root->val;
    }
    void solve(TreeNode* root){
        if(!root) return;
        
        int count = 0;

        int totalsum = findsum(root,count);
        cout<<count;
        if(root->val == (totalsum/count)) result++;

        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }
};
