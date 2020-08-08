// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void bottomViewUtil(Node* node, int current_level, int hd, map<int , pair<int, int> > *mp){
    if(node == NULL){
        return;
    }
    
    auto it = (*mp).find(hd);
    
    if(it != (*mp).end() && it->second.second <= current_level){
        it->second.first =  node->data;
        it->second.second =  current_level;
    }
    else {
        (*mp).insert({hd, {node->data, current_level}});
    }
    
    bottomViewUtil(node->left, current_level+1, hd-1, mp);
    bottomViewUtil(node->right, current_level+1, hd+1, mp);
}
// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   // Your Code Here
   int root_level = 0;
   map<int,pair<int,int>> mp;
   vector<int> v;
   bottomViewUtil(root, root_level, root_level, &mp);
   for(auto data : mp){
      v.push_back(data.second.first);
   }
   return v;
}