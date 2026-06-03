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
    bool dfs(TreeNode* root, double checkMin, double checkMax){
        if(!root){
            return true;
        }

        if(!(root->val > checkMin && root->val < checkMax)){
            return false;
        }

        return dfs(root->left, checkMin, root->val) && dfs(root->right, root->val, checkMax);
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, -std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
    }
};