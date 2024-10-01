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
    void solve(TreeNode* root,vector<int>& palin){
        if(!root) return;

        palin[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int oddfreq = 0;
            for(int i = 0;i<10;i++){
                if(palin[i]%2 != 0) oddfreq++;
            }
            if(oddfreq<=1) result++;
        }
        solve(root->left,palin);
        solve(root->right,palin);
        palin[root->val]--; // if we take as a refrence then we have to roll back otherwise it take copy automatically rollback this
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> palin(10,0);
        solve(root,palin);
        return result;
    }
};
