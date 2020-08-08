//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topViewUtil(Node* node, int current_level, int hd, map<int , pair<int, int> > *mp){
    if(node == NULL){
        return;
    }
    
    auto it = (*mp).find(hd);
    
    if(it != (*mp).end() && it->second.second > current_level){
        it->second.first =  node->data;
        it->second.second =  current_level;
    }
    else {
        (*mp).insert({hd, {node->data, current_level}});
    }
    
    topViewUtil(node->left, current_level+1, hd-1, mp);
    topViewUtil(node->right, current_level+1, hd+1, mp);
}

void topView(struct Node *root)
{
    //Your code here
    int root_level = 0;
   map<int,pair<int,int>> mp;
   topViewUtil(root, root_level, root_level, &mp);
   for(auto data : mp){
      cout<<data.second.first<<" ";
   }
   
}
