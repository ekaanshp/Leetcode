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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> bfs;
        bfs.push(root);

        int level = 0;
        while(!bfs.empty()){
            int queueSize = bfs.size();
            std::vector<int> order;
            for(int i = 0; i < queueSize; i++){
                TreeNode* node = bfs.front();
                bfs.pop();
                
                order.push_back(node->val);

                if(node->left){
                    bfs.push(node->left);
                }
                if(node->right){
                    bfs.push(node->right);
                }
            }
            if(level % 2 == 1){
                std::reverse(order.begin(), order.end());
            }
            level++;

            result.push_back(order);
        }
        return result;
    }
};