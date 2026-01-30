struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createAndAddNodes(NODE first) {
	NODE temp, q;
	int x;
	printf("Enter element : ");
	scanf("%d", &x);
	while(x != -1) {
		temp = (NODE)malloc(sizeof(struct node));
		temp->data = x;
		temp->next = NULL;
		if(first == NULL) {
			first = temp;
		} else {
			q->next = temp;
		}
		q = temp;
		printf("Enter element : ");
		scanf("%d", &x);
	}
	return first;  
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("Elements in the list are : ");
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}

NODE concatenate(NODE t1, NODE t2) {
	// Write the code
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
int find(struct node* ans,int key){
	struct node* temp=ans;
	while(temp){
		if(temp->data==key){
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
NODE unionSLL(NODE l1, NODE l2) {
	// Write the code
	if(l1==NULL){
		return l2;
	}
	if(l2==NULL){
		return l1;
	}
	struct node* ans=NULL;
	struct node* t1=l1;
	struct node* t2=l2;
	while(t1){
		if(ans==NULL){
			ans=malloc(sizeof(struct node));
			ans->next=NULL;
			ans->data=t1->data;
		}
		if(!find(ans,t1->data)){
			struct node* temp=malloc(sizeof(struct node));
			temp->data=t1->data;
			temp->next=NULL;
			struct node* T=ans;
			while(T->next){
				T=T->next;
			}
			T->next=temp;
			
		}
		t1=t1->next;
	}

	while(t2){
		if(ans==NULL){
			ans=malloc(sizeof(struct node));
			ans->next=NULL;
			ans->data=t2->data;
		}
		if(!find(ans,t2->data)){
			struct node* temp=malloc(sizeof(struct node));
			temp->data=t2->data;
			temp->next=NULL;
			struct node* T=ans;
			while(T->next){
				T=T->next;
			}
			T->next=temp;
			
		}
		t2=t2->next;
	}
	return ans;
}