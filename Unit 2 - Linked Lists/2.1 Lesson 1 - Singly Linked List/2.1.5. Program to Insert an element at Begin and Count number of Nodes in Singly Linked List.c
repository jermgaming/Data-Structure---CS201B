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

NODE insertAtBegin(NODE first, int x) {
	struct node* temp=malloc(sizeof(struct node));
	temp->data=x;
	if(first==NULL){
		first=temp;
		return first;
	}
	temp->next=first;
	first=temp;
	return first;
	
}

int count(NODE first) {
	int ans=0;
	struct node* temp=first;
	while(temp){
		ans++;
		temp=temp->next;
	}
	return ans;
}

void traverseList(NODE first) {
	NODE temp = first;
	while (temp != NULL) {
		printf("%d --> ",temp -> data);
		temp = temp -> next;
	}
	printf("NULL\n");
}