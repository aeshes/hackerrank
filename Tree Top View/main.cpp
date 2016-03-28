/*
You are given a pointer to the root of a binary tree. 
Print the top view of the binary tree.
You only have to complete the function.
For example :

     3
   /   \
  5     2
 / \   / \
1   4 6   7
 \       /
  9     8
Top View : 1 -> 5 -> 3 -> 2 -> 7
*/

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void TraverseLeft(node *root)
{
    if(root)
    {
        TraverseLeft(root->left);
        std::cout << root->data << " ";
    }
}

void TraverseRight(node *root)
{
    if(root)
    {
        std::cout << root->data << " ";
        TraverseRight(root->right);
    }
}

void TopView(node * root)    
{    
    if(root)
    {
        TraverseLeft(root);
        TraverseRight(root->right);
    }
}