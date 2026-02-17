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

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
}

NODE insertAtBeginInDLL(NODE head, int x) {
	NODE newNode=createNodeInDLL();
	newNode->data=x;
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
	return head;
}
int searchPosOfEleInDLL(NODE first, int element) { 
	int pos=1;
	NODE temp=first;
	while(temp){
		if(temp->data==element){
			return pos;
		}
		temp=temp->next;
		pos++;
	}
	return 0;
}