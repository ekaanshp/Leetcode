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
    bool sameTree(TreeNode* node, TreeNode* subNode){
        if(!node && !subNode){
            return true;
        }

        if(node && subNode && node->val == subNode->val){
            bool left = sameTree(node->left, subNode->left);
            bool right = sameTree(node->right, subNode->right);
            return left && right;
        }

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            return true;
        }
        if(!root){
            return false;
        }

        if(sameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};