struct node {
	int data;
	struct node *left, *right;
};
typedef struct node *BSTNODE;

struct stacknode {
	BSTNODE node;
	struct stacknode * next;
};

typedef struct stacknode * STKNODE;
STKNODE top = NULL;
int isempty() {
	if(top == NULL) {
		return 1;
	}
	return 0;
}
void push(BSTNODE b) {
	STKNODE temp;
	temp = (STKNODE)malloc(sizeof(struct stacknode));
	if(temp == NULL) {
		printf("Stack is overflow.\n");
	} else {
		temp -> node = b;
		temp -> next = top;
		top = temp;
	}
}
BSTNODE peek() {
	if (top == NULL) {
		return NULL;
	}
	return top->node;
}
BSTNODE pop() {
	STKNODE temp;
	BSTNODE b;
	if(top == NULL) {
		printf("Stack is underflow.\n");
	} else {
		temp = top;
		top = top -> next;
		b = temp->node;
		free(temp);
	}
		return b;
}

STKNODE newStackNode(BSTNODE b) {
	STKNODE temp =  (STKNODE)malloc(sizeof(struct node));
	temp->node = b;
	temp->next = NULL;
	return temp;
}
BSTNODE newNodeInBST(int item) {
	BSTNODE temp =  (BSTNODE)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorderInBST(BSTNODE root) {
	// Fill the function
	if(!root) return;
	inorderInBST(root->left);
	printf("%d ",root->data);
	inorderInBST(root->right);
}
BSTNODE insertNodeInBST(BSTNODE node, int ele) {
	if (node == NULL) {
		printf("Successfully inserted.\n");
		return newNodeInBST(ele);	
	}
	if (ele < node->data)
		node->left  = insertNodeInBST(node->left,ele);
	else if (ele > node->data)
		node->right = insertNodeInBST(node->right,ele);
	else
		printf("Element already exists in BST.\n");
	return node;
}
BSTNODE minValueNode(BSTNODE node) {
	// Fill the function
	return node;
}
BSTNODE deleteNodeInBST(BSTNODE root, int ele) {
	if (root == NULL) {
		printf("Cannot find %d in the binary search tree.\n",ele);
		return root;
	}
	if (ele < root->data)
		root->left = deleteNodeInBST(root->left,ele);
	else if (ele > root->data)
		root->right = deleteNodeInBST(root->right,ele);
	else {
		if (root->left == NULL) {
			BSTNODE temp = root->right;
			printf("Deleted %d from binary search tree.\n",ele);
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			BSTNODE temp = root->left;
			printf("Deleted %d from binary search tree.\n",ele);
			free(root);
			return temp;
		}
		BSTNODE temp = minValueNode(root->right);
		root->data = temp->data;
		temp->data = ele;
		root->right = deleteNodeInBST(root->right,ele);
    }
	return root;
}