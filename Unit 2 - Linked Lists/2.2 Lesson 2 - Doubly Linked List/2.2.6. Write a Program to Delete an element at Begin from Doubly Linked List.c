struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

NODE insertAtBeginInDLL(NODE first, int x) {
	NODE temp=createNodeInDLL();
	temp->data=x;
	temp->next=first;
	first=temp;
	return first;
}

NODE deleteAtBeginInDLL(NODE first) {
	if(first==NULL){
		printf("Can't delete the elements\n");
		return NULL;
	}
	if(first->next==NULL){
		printf("The deleted element from DLL : %d\n",first->data);
		free(first);
		return NULL;
	}

	NODE temp=createNodeInDLL();
	printf("The deleted element from DLL : %d\n",first->data);
	temp=first;
	first=first->next;
	first->prev=NULL;
	free(temp);
	return first;
}

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
}