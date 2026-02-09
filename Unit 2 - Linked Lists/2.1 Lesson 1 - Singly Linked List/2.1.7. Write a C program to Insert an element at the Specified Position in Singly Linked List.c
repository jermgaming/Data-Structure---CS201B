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

NODE insertAtPosition(NODE first, int pos, int x) {
	
	// Write your code here
	NODE node=createNode();
	node->data=x;
	if(pos==1){
		node->next=first;
		first=node;
		return first;
	}
	NODE temp=first;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	if(!temp){
		printf("No such position in SLL so insertion is not possible\n");
	}
	node->next=temp->next;
	temp->next=node;
	return first;
}

void traverseList(NODE first) {
	NODE temp=first;
	while(temp){
		printf("%d --> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	// Write your code here
	
}