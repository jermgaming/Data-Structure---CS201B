struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> next = NULL;
	return temp;
}

int countInDLL(NODE first) {
	int count=0;
	NODE temp=first;
	while(temp){
		count++;
		temp=temp->next;
	}
	return count;
}

NODE insertAtBeginInDLL(NODE first, int x) {
	NODE temp=createNodeInDLL();
	temp->data=x;
	temp->next=first;
	first->prev=temp;
	first=temp;
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