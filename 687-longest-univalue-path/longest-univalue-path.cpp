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
    int dfs(TreeNode* node, int& longest){
        if(!node){
            return 0;
        }

        int leftLength = dfs(node->left, longest);
        int rightLength = dfs(node->right, longest);

        int leftArrow = 0;
        int rightArrow = 0;

        if(node->left && node->left->val == node->val){
            leftArrow = leftLength + 1;
        }
        if(node->right && node->right->val == node->val){
            rightArrow = rightLength + 1;
        }

        longest = std::max(longest, leftArrow + rightArrow);
        return std::max(leftArrow, rightArrow);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int max = 0;
        dfs(root, max);
        return max;
    }
};