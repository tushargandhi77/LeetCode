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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        int level = 0;

        while(!que.empty()){
            int n = que.size();
            vector<TreeNode*> nodes;
            while(n--){
                TreeNode* temp = que.front();
                que.pop();

                nodes.push_back(temp);

                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            if(level%2 == 1){
                int i = 0;
                int j = nodes.size()-1;
                while(i < j){
                    int tempval = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = tempval;
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};
