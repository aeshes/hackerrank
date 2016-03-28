/*
You are given a pointer to the root of a binary tree. You need to print the level 
order traversal of this tree. In level order traversal, we visit the nodes level by 
level from left to right.
You only have to complete the function.
For example:

         3
       /   \
      5     2
     / \    /
    1   4  6

For the above tree, the level order traversal is 3 -> 5 -> 2 -> 1 -> 4 -> 6.
*/


#include <queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    if(!root) return;
    
    std::queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *x = q.front();
        std::cout << x->data << " ";
        if(x->left)  q.push(x->left);
        if(x->right) q.push(x->right);
        q.pop();
    }
}