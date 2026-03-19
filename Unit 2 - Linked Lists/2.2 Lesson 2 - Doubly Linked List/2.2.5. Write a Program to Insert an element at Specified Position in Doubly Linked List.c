struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL(int x) {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->data=x;
	return temp;
}

NODE insertAtPositionInDLL(NODE first, int position, int x) { 
	NODE temp=first;
	NODE newNode=createNodeInDLL(x);
	if(!first && position==1){
		return newNode;
	}
	if(position==1){
		newNode->next=first;
		first->prev=newNode;
		first=newNode;
		return first;
	}
	for(int i=1;i<position-1;i++){
		temp=temp->next;
	}
	//printf(" %d temp data",temp->data);
	if(!temp){
		printf("No such position in DLL so insertion is not possible\n");
		return first;
	}
	if(!temp->next){
		newNode->prev=temp;
		temp->next=newNode;
		return first;
	}
	newNode->next=temp->next;
	newNode->prev=temp;
	temp->next->prev=newNode;
	temp->next=newNode;
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