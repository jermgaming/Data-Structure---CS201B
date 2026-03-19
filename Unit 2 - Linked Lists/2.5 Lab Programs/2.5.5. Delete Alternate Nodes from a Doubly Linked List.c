// Type Content here...
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	struct node* next;
	int data;
};

struct node* createNode(int data){
	struct node* newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
struct node* insertTail(struct node* head,int data){
	struct node* newNode=createNode(data);
	if(!head){
		return newNode;
	}

	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
	return head;
}


void print(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d <-> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main(){
	int n,data;
	struct node* head=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		head=insertTail(head,data);
	}
	
	print(head);
	
	struct node* temp=head->next;
	do{
		struct node* p=temp->prev;
		struct node* n=temp->next;
		p->next=n;
		temp->prev=NULL;
		temp->next=NULL;
		free(temp);
		if(n->next){
			n->prev=p;
		}
		temp=n->next;
	}while(temp);
	
	print(head);
	return 0;
}