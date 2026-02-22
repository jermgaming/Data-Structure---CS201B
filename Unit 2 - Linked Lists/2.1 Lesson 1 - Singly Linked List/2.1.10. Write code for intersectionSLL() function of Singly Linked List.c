struct node {
	int data;
	struct node *next;
};
typedef struct node * NODE;

NODE createNode(){
	NODE node=malloc(sizeof(struct node));
	node->next=NULL;
	return node;
}

NODE create(int data){
	NODE node=malloc(sizeof(struct node));
	node->next=NULL;
	node->data=data;
	return node;
}

void printN(NODE head){
	NODE temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}printf("\n");
}
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

NODE findMid(NODE first){
	NODE slow=first;
	NODE fast=first->next;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

NODE merge(NODE left,NODE right){
	if(!left) return right;
	if(!right) return left;
	NODE ans=create(-1);
	NODE temp=ans;
	while(left && right){
		if(left->data<right->data){
			temp->next=left;
			temp=left;
			left=left->next;
		}else {
			temp->next=right;
			temp=right;
			right=right->next;
		}
	}

	if(left){
		temp->next=left;
	}
	if(right){
		temp->next=right;
	}
	ans=ans->next;
	return ans;
	
}
NODE sort(NODE first) {
	// Write the code
	//base case
	if(first==NULL || first->next==NULL){
		return first;
	}
	NODE mid=findMid(first);
	NODE left=first;
	NODE right=mid->next;
	mid->next=NULL;

	left=sort(left);
	right=sort(right);

	NODE ans=merge(left,right);
	return ans;
	
}

NODE add(NODE l3,int x) {
	// Write the code
	NODE temp=l3;
	while(temp->next){
		temp=temp->next;
	}
	NODE node=createNode();
	node->data=x;
	temp->next=node;
	return l3;
}
void insertTail(NODE *ans,int data){
	if(!*ans){
		*ans=create(data);
		return;
	} 
	NODE t=create(data);
	NODE temp=*ans;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=t;
	//return *ans;
}
NODE intersectionSLL(NODE l1,NODE l2) {
	// Write the code
	NODE ans=NULL;
	while(l1 != NULL && l2 != NULL) {
		if(l1->data < l2->data) {
			l1 = l1->next;
		}
		else if(l2->data < l1->data) {
			l2 = l2->next;
		}
		else {
			insertTail(&ans, l1->data);
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	return ans;
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("Elements in the list are : ");
		while (q != NULL) {
			printf("%d---> ", q -> data);
			q = q -> next;
		}
		printf("NULL\n");
	}
}