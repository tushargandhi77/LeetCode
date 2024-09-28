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
    int solve(TreeNode* root,int start){
        if(!root) return 0;
        int Lh = solve(root->left,start);
        int rh = solve(root->right,start);

        if(root->val == start){
            result = max(Lh,rh);
            return -1;
        }
        else if(Lh >= 0 && rh >= 0){
            return max(Lh,rh) + 1;
        }
        else{
            int d = abs(Lh) + abs(rh);
            result = max(d,result);
            return min(Lh,rh) - 1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return result;
    }
};
