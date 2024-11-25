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
    vector<vector<int>> result;
    void solve(TreeNode* root,int target,int sum,vector<int> path){
        if(!root) return;

        sum+= root->val;
        path.push_back(root->val);
        if(sum==target && root->left == NULL && root->right == NULL){
            result.push_back(path);
        }

        solve(root->left,target,sum,path);
        solve(root->right,target,sum,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int sum = 0;
        solve(root,targetSum,sum,path);
        return result;
    }
};
