/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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

int height(Node* node){
    if(node==NULL){
        return 0;
    }
    return 1+max(height(node->left), height(node->right));
}

void printSpiralUtil(Node* node, int level, bool *ltr){
    if(node == NULL || level < 0){
        return;
    }
    if(level == 0){
        cout<<node->data<<" ";
    }
    else if(*ltr){
        printSpiralUtil(node->left, level-1, ltr);
        printSpiralUtil(node->right, level-1, ltr);    
    }
    else {
        printSpiralUtil(node->right, level-1, ltr);
        printSpiralUtil(node->left, level-1, ltr);
    }
    
}

void printSpiral(Node *root)
{
    //Your code here
    int h = height(root);
    bool ltr = true;
    for(int i=0;i<h;i++){
        ltr = !ltr;
        printSpiralUtil(root, i, &ltr);
    }
}
