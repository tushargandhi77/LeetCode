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
    int stepsin(vector<int>& vec,int n){
        int swaps = 0;
        vector<int> sortedvec(begin(vec),end(vec));

        sort(sortedvec.begin(),sortedvec.end());

        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[vec[i]] = i;
        }

        for(int i = 0;i<n;i++){
            if(vec[i] == sortedvec[i]) continue;

            int currIdx = mp[sortedvec[i]];
            mp[vec[i]] = currIdx;
            swap(vec[currIdx],vec[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int result = 0;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int N = que.size();
            vector<int> vec;
            while(N--){
                TreeNode* node = que.front();
                que.pop();

                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result += stepsin(vec,vec.size());
        }
        return result;
    }
};
