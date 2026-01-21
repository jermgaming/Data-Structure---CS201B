// Type Content here...
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* createNode(int x){
	struct node* temp=malloc(sizeof(struct node));
	if(!temp){
		printf("Memory allocation failed\n");
		exit(1);
	}
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void printNode(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void insertNode(struct node** head,int x){
	struct node* newNode=createNode(x);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	struct node*temp = *head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode;
}

struct node* reverse(struct node** head){
	struct node* prev=NULL;
	struct node* curr=*head;
	while(curr){
		struct node* forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	return prev;
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	while(n--){
		int x;
		scanf("%d",&x);
		insertNode(&head,x);
	}
	printNode(head);
	head=reverse(&head);
	printNode(head);
	return 0;
}