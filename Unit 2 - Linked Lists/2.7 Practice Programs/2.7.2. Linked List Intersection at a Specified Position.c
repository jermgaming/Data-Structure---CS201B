#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* createNode(int data){
	struct node* head=malloc(sizeof(struct node));
	head->next=NULL;
	head->data=data;
	return head;
}
struct node* insertTail(struct node* head,int data){
	struct node* newNode=createNode(data);
	if(!head) return newNode;
	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode;
	return head;
}

void print(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d",temp->data);
		if(temp->next){
			printf(" ");
		}
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int l1,l2;
	struct node* head1=NULL;
	struct node* head2=NULL;
	scanf("%d",&l1);
	while(l1--){
		int data;
		scanf("%d",&data);
		head1=insertTail(head1,data);
	}
	scanf("%d",&l2);

	while(l2--){
		int data;
		scanf("%d",&data);
		head2=insertTail(head2,data);
	}
	int p;
	scanf("%d",&p);
	struct node* temp=head1;
	while(p--){
		temp=temp->next;
	}
	struct node* tail=head2;
	while(tail->next){
		tail=tail->next;
	}
	tail->next=temp;
	print(head1);
	print(head2);
	return 0;
}