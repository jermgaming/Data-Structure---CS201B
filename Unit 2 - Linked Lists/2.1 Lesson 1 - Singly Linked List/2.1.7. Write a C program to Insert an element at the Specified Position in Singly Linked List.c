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
	if(first==NULL && pos!=1){
		printf("No such position in SLL so insertion is not possible\n");
		return NULL;
	}
	if(first==NULL){
		if(pos==1){
			first=createNode();
			first->data=x;
			return first;
		}
		return first;
	}
	if(pos==1){
			NODE temp=createNode();
			temp->data=x;
			temp->next=first;
			first=temp;
			return first;
	}
	
	NODE temp=first;
	NODE prev=NULL;
	int count=1;
	while(temp && count <pos){
		prev=temp;
		temp=temp->next;
		count++;
	}
	if(temp==NULL && count<pos){
		printf("No such position in SLL so insertion is not possible\n");
		return first;
	}
	NODE newNode=createNode();
	newNode->data=x;
	newNode->next=temp;
	prev->next=newNode;
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