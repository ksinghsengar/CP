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
    bool isSym(TreeNode * node1, TreeNode* node2){
        if(node1 == NULL ^ node2 == NULL){
            return false;
        }
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        return node1->val == node2->val &&
            isSym(node1->left, node2->right) &&
            isSym(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return isSym(root->left, root->right);
    }
};