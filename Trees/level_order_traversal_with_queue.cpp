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

//You are required to complete this method
vector<int> levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q;
  vector<int> v;
  if(node == NULL) return v;
  q.push(node);
  while(!q.empty()) {
      Node* temp = q.front();
      v.push_back(temp->data);
      q.pop();
      if(temp->left != NULL) q.push(temp->left);
      if(temp->right != NULL) q.push(temp->right);
  }
  return v;
}