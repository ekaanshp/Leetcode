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
    int dfs(TreeNode* root, int maxVal){
        if(!root){
            return 0;
        }

        int result = 0;
        if(root->val >= maxVal){
            result += 1;
            maxVal = root->val;
        }

        int left = dfs(root->left, maxVal);
        int right = dfs(root->right, maxVal);

        return result + left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};