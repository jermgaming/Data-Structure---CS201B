#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* insertAthead(struct node* head){
	int x;
	scanf("%d",&x);
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->next=NULL;
		head->data=x;
		return head;
	}
	struct node* temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}

int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	while(n--){
		head=insertAthead(head);
	}

	struct node* temp=head;
	
	int x;
	scanf("%d",&x);

	int ans=0;
	printf("Given linked list: ");
	while(temp){
		printf("%d-->",temp->data);
		if(temp->data==x){
			ans++;
		}
		temp=temp->next;
	}
	printf("Null\n");
	printf("%d",ans);
	return 0;
}