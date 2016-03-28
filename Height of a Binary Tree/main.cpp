/*
The height of a binary tree is the number of nodes on the largest path from root 
to any leaf. You are given a pointer to the root of a binary tree. 
Return the height of the tree.
You only have to complete the function. 
*/

/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root)
{
	int left = 0, right = 0;
	if(root == NULL)
		return 0;
	  
	if(root->left)  left  = height(root->left);
	if(root->right) right = height(root->right);
	int max = left > right ? left : right;

	return max + 1;
}