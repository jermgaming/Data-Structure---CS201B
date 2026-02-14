#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* createNode(struct node* next,int data){
	struct node* ans=malloc(sizeof(struct node));
	ans->next=next;
	ans->data=data;
	return ans;
}
struct node* insertAtBeginning(struct node* head,int data){
	if(!head){
		return createNode(NULL,data);
	}
	struct node* temp=createNode(head,data);
	head=temp;
	return head;
}

void print(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("Null\n");
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	int x;
	while(n--){
		scanf("%d",&x);
		head=insertAtBeginning(head,x);
	}

	int num;
	scanf("%d",&num);
	
	printf("Initial Linked List: ");
	print(head);
	printf("LinkedList after deletion: ");
	
	while(num--){
		head=head->next;
	}
	print(head);
	return 0;
}