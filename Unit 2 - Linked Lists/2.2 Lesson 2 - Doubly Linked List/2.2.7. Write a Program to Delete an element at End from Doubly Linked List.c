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

NODE insertAtEndInDLL(NODE first, int x) {
	NODE temp, lastNode = first;
	temp = createNodeInDLL();
	temp -> data = x;
	if (first == NULL) {
		first = temp;
	} else {
		while (lastNode -> next != NULL) {
			lastNode = lastNode -> next;
		}
		lastNode -> next = temp;
		temp -> prev = lastNode;
	}
	return first;
}

NODE deleteAtEndInDLL(NODE first) {
	if(first==NULL){
		return NULL;
	}
	if(first->next==NULL){
		NODE temp=first;
		printf("The deleted element from DLL : %d\n",temp->data);
		free(temp);
		return NULL;
	}
	NODE temp=first;
	while(temp->next){
		temp=temp->next;
	}
	printf("The deleted element from DLL : %d\n",temp->data);
	NODE prevNode=temp->prev;
	prevNode->next=NULL;
	temp->prev=NULL;
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
