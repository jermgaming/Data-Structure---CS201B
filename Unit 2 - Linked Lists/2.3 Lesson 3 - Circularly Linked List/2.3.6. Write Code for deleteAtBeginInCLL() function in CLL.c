struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL(int x) {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	temp->data=x;
	return temp;
}

NODE insertAtBeginInCLL(NODE first, int x) {
	NODE newNode=createNodeInCLL(x);
	if(!first){
		newNode->next=newNode;
		first=newNode;
		return first;
	}
	NODE temp=first;
	do{
		temp=temp->next;
	}while(temp->next!=first);

	newNode->next=first;
	temp->next=newNode;
	first=newNode;
	return first;
}

NODE deleteAtBeginInCLL(NODE first) {
	if(first->next==first){
		printf("The deleted element from CLL : %d\n",first->data);
		free(first);
		return NULL;
	}
	NODE temp=first;
	do{
		temp=temp->next;
	}while(temp->next!=first);
	printf("The deleted element from CLL : %d\n",first->data);
	first=first->next;
	temp->next=first;
	return first;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}