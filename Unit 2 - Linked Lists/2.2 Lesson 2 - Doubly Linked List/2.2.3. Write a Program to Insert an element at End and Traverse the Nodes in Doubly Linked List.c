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
	if(!first){
		first=createNodeInDLL();
		first->data=x;
		return first;
	}else {
		NODE temp=first;
		while(temp->next){
			temp=temp->next;
		}
		NODE newNode=createNodeInDLL();
		newNode->data=x;
		temp->next=newNode;
		newNode->prev=temp;
		return first;
	}
}

void traverseListInDLL(NODE first) {
	NODE temp=first;
	while(temp){
		printf("%d <--> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}