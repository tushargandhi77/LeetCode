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
    bool findpath(TreeNode* root,int node,string& path){
        if(!root) return false;

        if(root->val == node){
            return true;
        }

        path.push_back('L');
        if(findpath(root->left,node,path) == true) return true;

        path.pop_back();

        path.push_back('R');
        if(findpath(root->right,node,path) == true) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int source, int destination) {
        string rootTosource = "";
        string rootTodestination = "";

        findpath(root,source,rootTosource);
        findpath(root,destination,rootTodestination);

        int l = 0;
        while(l < rootTosource.size() && l < rootTodestination.size() && rootTosource[l] == rootTodestination[l]){
            l++;
        }
        string result = "";
        for(int i = 0;i<rootTosource.size()-l;i++){
            result.push_back('U');
        }
        for(int i = l;i<rootTodestination.size();i++){
            result.push_back(rootTodestination[i]);
        }
        return result;
    }
};
