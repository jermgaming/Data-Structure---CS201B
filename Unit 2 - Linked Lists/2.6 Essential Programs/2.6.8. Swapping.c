#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* createNode(int data){
	struct node* ans=malloc(sizeof(struct node));
	ans->data=data;
	ans->next=NULL;
	return ans;
}
struct node* insertTail(struct node* head,int data){
	if(!head){
		return createNode(data);
	}

	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}

	struct node* newNode=createNode(data);
	temp->next=newNode;
	return head;
}

void print(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	//printf("Null\n");
}
int main(){
	int n;
	scanf("%d",&n);
	int length=n;
	int x;
	struct node* head=NULL;
	while(n--){
		scanf("%d",&x);
		head=insertTail(head,x);
	}
	int k;
	scanf("%d",&k);
	struct node* t1=head;
	struct node* t2=head;
	int num=k;
	while(--num){
		t1=t1->next;
	}
	num=length-k;
	//printf("num is %d ",num);
	while(num--){
		t2=t2->next;
	}
	int temp=t2->data;
	t2->data=t1->data;
	t1->data=temp;
	print(head);
	return 0;
	
}