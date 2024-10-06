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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        int level = 0;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int> result(n,0);
            int j = 0;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                result[j] = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                j++;
            }
            if(level%2==0){
                if(result.size() == 1 && result[0]%2 == 0) return false;
                for(int i = 1;i<result.size();i++){
                    int prev = result[i-1];
                    int curr = result[i];
                    if(prev >= curr || prev%2 == 0 || curr%2 == 0 ) return false;
                }
            }
            else{
                if(result.size() == 1 && result[0]%2 != 0) return false;
                for(int i = 1;i<result.size();i++){
                    int prev = result[i-1];
                    int curr = result[i];
                    if(prev <= curr || prev%2 != 0 || curr%2 != 0) return false;
                }
            }
            level++;
        }
        return true;
    }
};
