struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createAndAddNodes(NODE first) {
	int x;
	printf("Enter element : ");
	scanf("%d",&x);
	if(x==-1){
		return first;
	}
	if(first==NULL){
		first=malloc(sizeof(struct node));
		first->next=NULL;
		first->data=x;
	}else{
		struct node* temp=first;
		while(temp->next){
			temp=temp->next;
		}
		struct node* n=malloc(sizeof(struct node));
		n->next=NULL;
		n->data=x;
		temp->next=n;
	}
	return createAndAddNodes(first);
}

NODE concatenate(NODE t1, NODE t2) {
	if(t1==NULL){
		return t2;
	}
	if(t2==NULL){
		return t1;
	}
	struct node* temp=t1;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=t2;
	return t1;
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}