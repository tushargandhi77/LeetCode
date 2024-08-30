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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int maxsum = INT_MIN;
        int currlevel = 1;
        int level = 0;

        while(!que.empty()){
            int n = que.size();
            int sum = 0;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(sum > maxsum){
                maxsum = sum;
                level = currlevel;
            }
            currlevel++;
        }
        return level;
    }
};
