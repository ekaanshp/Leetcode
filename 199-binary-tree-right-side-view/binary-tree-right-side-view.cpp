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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }

        std::vector<int> result;
        std::queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int queueSize = bfs.size();
            result.push_back(bfs.back()->val);

            for(int i = 0; i < queueSize; i++){
                TreeNode* node = bfs.front();
                bfs.pop();

                if(node->left){
                    bfs.push(node->left);
                }
                if(node->right){
                    bfs.push(node->right);
                }
            }
        }
        return result;
    }
};