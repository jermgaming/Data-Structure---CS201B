struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE addNodesInCLL(NODE first, int x) {
	
	// Write your code here
	if(!first){
		first=createNodeInCLL();
		first->data=x;
		return first;
	}
	NODE temp=first;
	while(temp->next){
		temp=temp->next;
	}
	NODE newNode=createNodeInCLL();
	newNode->data=x;
	temp->next=newNode;
	return first;
	
}

void traverseListInCLL(NODE first) {
	
	// Write your code here
	if(!first){
		printf("Circular Linked List is empty\n");
		return;
	}
	NODE temp=first;
	//("The element in CLL are : ");
	while(temp){
		printf("%d --> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}