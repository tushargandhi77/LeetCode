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
    map<int,int> mp;
    void preorder(TreeNode* root,int level){
        if(!root) return;

        mp[level] += root->val;

        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        preorder(root,1);
        int maxSum = INT_MIN;
        int resultlevel = 0;

        for(auto &it : mp){
            int level = it.first;
            int sum = it.second;
            if(sum > maxSum){
                maxSum = sum;
                resultlevel = level;
            }
        }
        return resultlevel;
    }
};
