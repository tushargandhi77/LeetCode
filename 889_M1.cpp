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
    TreeNode* solve(int prestart,int preend,int poststart,vector<int>& preorder,vector<int>& postorder){
        if(prestart > preend){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        if(prestart == preend){
            return root;
        }

        int  nextNode = preorder[prestart+1]; // root of left sub tree

        int j = poststart;
        while(postorder[j] != nextNode){
            j++;
        }

        int num = j-poststart+1;

        root->left = solve(prestart+1,prestart+num,poststart,preorder,postorder);
        root->right = solve(prestart+num+1,preend,j+1,preorder,postorder);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(0,preorder.size()-1,0,preorder,postorder);
    }
};
