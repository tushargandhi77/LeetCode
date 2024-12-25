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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> que;

        vector<int> result;

        que.push(root);

        while(!que.empty()){
            int N = que.size();
            int maxE = INT_MIN;
            while(N--){
                auto temp = que.front();
                que.pop();

                maxE = max(maxE,temp->val);

                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            result.push_back(maxE);
        }
        return result;
    }
};
