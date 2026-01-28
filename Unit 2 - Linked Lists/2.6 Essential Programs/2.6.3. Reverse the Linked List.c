#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void insertAtTail(struct node** head,struct node** tail){
	int x;
	scanf("%d",&x);
	if(*(head)==NULL && *(tail)==NULL){
		*(head)=malloc(sizeof(struct node));
		(*(head))->next=NULL;
		(*(head))->data=x;
		*(tail)=*(head);
		return;
	}
	struct node* temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	(*(tail))->next=temp;
	(*(tail))=(*(tail))->next;
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	struct node* tail=NULL;
	while(n--){
		insertAtTail(&head,&tail);
	}
	//reverse
	struct node* prev=NULL;
	struct node* curr=head;
	while(curr){
		struct node* forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	head=prev;
	struct node* temp=head;
	
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
}