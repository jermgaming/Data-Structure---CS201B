// REfer the driver code and complete the Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
   // base case 
	if(root==NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ",root->data);
}