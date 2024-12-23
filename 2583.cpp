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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        queue<TreeNode*> que;

        que.push(root);
        int level = 0;
        while(!que.empty()){
            int n = que.size();
            long long sum = 0;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            pq.push(sum);
            if(pq.size() > k){
                pq.pop();
            }
            level++;
        }
        if(k > level) return -1;
        return pq.top();
    }
};
