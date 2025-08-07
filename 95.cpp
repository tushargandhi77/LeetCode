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

    vector<TreeNode*> solve(int start,int end){
        if(start > end) return {NULL};

        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        vector<TreeNode*> result;
        for(int i = start;i<=end;i++){
            vector<TreeNode*> leftNode = solve(start,i-1);
            vector<TreeNode*> rightNode = solve(i+1,end);

            for(auto L: leftNode){
                for(auto R: rightNode){
                    TreeNode* root = new TreeNode(i);
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
