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
	temp->next=NULL;
	temp->data=x;
	return temp;
}
void insertNodeAtTail(int x,struct node** head,struct node** tail){
	struct node* temp=createNode(x);
	if(*head==NULL && *tail==NULL){
		*tail=temp;
		*head=temp;
		return ;
	}
	
	(*tail)->next=temp;
	*tail=temp;
	return;
}
void printNode(struct node* head){
	if(head==NULL){
		printf("Empty List\n");
	}else {
		struct node* temp=head;
		while(temp){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	struct node* tail=NULL;
	while(n--){
		int x;
		scanf("%d",&x);
		insertNodeAtTail(x,&head,&tail);
	}
	int x;
	scanf("%d",&x);
	insertNodeAtTail(x,&head,&tail);
	printNode(head);
	return 0;
}