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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        std::queue<std::pair<TreeNode*, unsigned long long>> queue;
        queue.push({root, 0});
        unsigned long long maxWidth = 0;

        while(!queue.empty()){
            int levelSize = queue.size();

            unsigned long long leftPosition = queue.front().second;
            unsigned long long rightPosition = -1;

            for(int i = 0; i < levelSize; i++){
                auto [node, pos] = queue.front();
                queue.pop();

                if(i == levelSize - 1){
                    rightPosition = pos;
                }

                unsigned long long normalizedPos = pos - leftPosition;
                if(node->left){
                    queue.push({node->left, 2 * normalizedPos});
                }
                if(node->right){
                    queue.push({node->right, 2 * normalizedPos + 1});
                }
            }

            unsigned long long currentWidth = rightPosition - leftPosition + 1;
            if (currentWidth > maxWidth) {
                maxWidth = currentWidth;
            }
        }
        return (int)maxWidth;
    }
};