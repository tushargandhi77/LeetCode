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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*,string>> que;
        string s = "";
        s = char(root->val + 'a') + s;
        que.push({root,s});

        string result = "";
        while(!que.empty()){
            auto P = que.front();
            que.pop();

            TreeNode* Node = P.first;
            string curr = P.second;

            if(Node->left){
                string s = char(Node->left->val + 'a') + curr;
                que.push({Node->left,s});
            }
            if(Node->right){
                string s = char(Node->right->val + 'a') + curr;
                que.push({Node->right,s});
            }

            if(Node->left == NULL && Node->right == NULL){
                if(result == "" || result > curr){
                    result = curr;
                }
            }

        }
        return result;
    }
};
