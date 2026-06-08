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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        std::vector<TreeNode*> stack;
        TreeNode* current = root;

        while(!stack.empty() || current){
            while(current){
                stack.push_back(current);
                current = current->left;
            }
            current = stack.back();
            stack.pop_back();

            n++;
            if(n == k){
                return current->val;
            }
            current = current->right;
        }
        return current->val;
    }
};