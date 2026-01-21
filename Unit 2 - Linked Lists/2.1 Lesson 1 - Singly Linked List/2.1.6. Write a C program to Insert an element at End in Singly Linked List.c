struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtEnd(NODE first, int x) {
	if(!first){
		first=createNode();
		first->data=x;
		return first;
	}
	struct node* temp=createNode();
	temp->data=x;
	struct node* copyFirst=first;
	while(copyFirst->next){
		copyFirst=copyFirst->next;
	}
	copyFirst->next=temp;
	return first;
}

void traverseList(NODE first) {
	struct node* temp=first;
	while(temp){
		printf("%d --> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}