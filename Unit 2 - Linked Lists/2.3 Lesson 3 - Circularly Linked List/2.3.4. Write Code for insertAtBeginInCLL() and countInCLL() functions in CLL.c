struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtBeginInCLL(NODE first, int x) {
	NODE newNODE=createNodeInCLL();
	newNODE->data=x;
	if(!first){
		newNODE->next=newNODE;
		return newNODE;
	}
	newNODE->next=first->next;
	first->next=newNODE;
	int temp=newNODE->data;
	newNODE->data=first->data;
	first->data=temp;
	return first;
}

int countInCLL(NODE first) {
	if(!first) return 0;
	int ans=0;
	NODE temp=first;
	do{
		ans++;
		temp=temp->next;
	}while(temp!=first);
	return ans;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}