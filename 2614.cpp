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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        vector<int> levelSum;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            int currsum = 0;
            while(n--){
                TreeNode* curr = que.front();
                que.pop();
                currsum += curr->val;

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            levelSum.push_back(currsum);
        }
        que.push(root);
        root->val = 0;
        int i = 1;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left){
                    curr->left->val = levelSum[i] - siblingSum;
                    que.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelSum[i] - siblingSum;
                    que.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};
