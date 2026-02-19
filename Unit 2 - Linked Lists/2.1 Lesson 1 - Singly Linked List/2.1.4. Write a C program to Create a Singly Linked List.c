struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	struct node* temp=malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

NODE addNodes(NODE first, int x) {
	if(first==NULL){
		struct node* t=createNode();
		t->data=x;
		t->next=NULL;
		first=t;
		return first;
	}else {
		struct node*temp=first;
		while(temp->next){
			temp=temp->next;
		}
		struct node* t=createNode();
		t->data=x;
		t->next=NULL;
		temp->next=t;
		return first;
	}
}

void traverseList(NODE first) {
	struct node* T=first;
	while(T){
		printf("%d --> ",T->data);
		T=T->next;
	}
	printf("NULL\n");
	
}