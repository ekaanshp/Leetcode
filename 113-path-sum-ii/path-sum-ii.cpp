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
    void dfs(TreeNode* node, int target, std::vector<std::vector<int>>& result, std::vector<int>& path){
        if(!node){
            return;
        }

        path.push_back(node->val);
        if(!node->left && !node->right){
            if(target == node->val){
                result.push_back(path);
            }
        }

        dfs(node->left, target - node->val, result, path);
        dfs(node->right, target - node->val, result, path);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        dfs(root, targetSum, result, path);
        return result;
    }
};