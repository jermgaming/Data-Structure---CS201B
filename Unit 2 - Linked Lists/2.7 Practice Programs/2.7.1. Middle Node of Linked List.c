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
	while(temp->next) temp=temp->next;
	temp->next=newNode;
	return head;
}

void print(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	while(n--){
		int data;
		scanf("%d",&data);
		head=insertTail(head,data);
	}
	struct node* slow=head;
	struct node* fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	printf("%d\n",slow->data);
	return 0;
}