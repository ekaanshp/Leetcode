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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            std::vector<int> level;
            int queueSize = bfs.size();
            for(int i = 0; i < queueSize; i++){
                TreeNode* node = bfs.front();
                bfs.pop();
                level.push_back(node->val);

                if(node->left){
                    bfs.push(node->left);
                }
                if(node->right){
                    bfs.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};