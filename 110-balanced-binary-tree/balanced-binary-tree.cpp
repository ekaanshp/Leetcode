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
    //pair of balanced and height
    std::pair<bool, int> dfs(TreeNode* node){
        if(!node){
            return {true, 0};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        bool balance = left.first && right.first && (std::abs(left.second - right.second) <= 1);
        return {balance, 1 + std::max(left.second, right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto pair = dfs(root);
        return pair.first;
    }
};