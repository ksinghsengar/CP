/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node * node){
    if(node == NULL){
        return 0;
    }
    return 1+ max(height(node->left), height(node->right));
}

void diameterUtil(Node* node, int *max_height){
    if(node == NULL) return;
    int height_sum = height(node->left) + height(node->right) + 1;
    if(*max_height < height_sum){
        *max_height = height_sum; 
    }
    diameterUtil(node->left, max_height);
    diameterUtil(node->right, max_height);
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    // Your code here
    int max_height = 0;
    diameterUtil(node, &max_height);
    return max_height;
}
