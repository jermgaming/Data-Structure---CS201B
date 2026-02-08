// Type Content here...
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* createNode(int x){
	struct node* temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}

struct node* insertNode(struct node* head,int x){
	if(head==NULL){
		head=createNode(x);
		return head;
	}
	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	struct node* newNode=createNode(x);
	temp->next=newNode;
	return head;
}

void printNode(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	while(n--){
		int data;
		scanf("%d",&data);
		head=insertNode(head,data);
	}
	
	struct node* slow=NULL;
	struct node* fast=head;
	while(fast && fast->next){
		if(!slow){
			slow=head;
		}else {
			slow=slow->next;
		}
		
		fast=fast->next->next;
	}
	int v;
	scanf("%d",&v);
	printNode(head);
	struct node* N=createNode(v);
	N->next=slow->next;
	slow->next=N;
	//printf("%d ",slow->data);
	printNode(head);
	return 0;
}