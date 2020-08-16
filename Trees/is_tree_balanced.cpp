/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

int height(Node* node){
    if(node == NULL) return 0;
    return 1+max(height(node->left), height(node->right));
}

// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root == NULL){
        return 1;
    }
    if(abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
     return 1;
    }
    return 0;
}
