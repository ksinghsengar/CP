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

void printSpiral(Node *root)
{
    //Your code here
    if(root == NULL){
        return;
    }
    
    stack<Node*> s1;
    stack<Node*> s2;
    
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* ele = s1.top();
            s1.pop();
            cout<<ele->data<<" ";
            if(ele->right != NULL) s2.push(ele->right);
            if(ele->left != NULL) s2.push(ele->left);
        }
        while(!s2.empty()){
            Node* ele = s2.top();
            s2.pop();
            cout<<ele->data<<" ";
            if(ele->left != NULL) s1.push(ele->left);
            if(ele->right != NULL) s1.push(ele->right);
        }
    }
    
}
