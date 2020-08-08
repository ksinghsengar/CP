/* A binary tree Node

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
int heightOfTree(Node * node){
    if(node == NULL){
        return 0;
    }
    return 1 + max(heightOfTree(node->left), heightOfTree(node->right));
} 

void levelOrderUtil(Node* node, int level, int current_level, vector<int> *v){
 if(node==NULL){
     return;
 }
 
 if(current_level == level){
     (*v).push_back(node->data);
 }
 
 levelOrderUtil(node->left, level, current_level+1, v);
 levelOrderUtil(node->right, level, current_level+1, v);
}

vector<int> levelOrder(Node* node)
{
  //Your code here
 
  vector<int> v;
  int height = heightOfTree(node);
  for(int i=0;i<height;i++){
      levelOrderUtil(node, i, 0, &v);
  }
  return v;
}