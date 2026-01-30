#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* insertAttail(struct node* head){
	int x;
	scanf("%d",&x);
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=x;
		head->next=NULL;
		return head;
	}
	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	struct node* newNode=malloc(sizeof(struct node));
	newNode->data=x;
	newNode->next=NULL;
	temp->next=newNode;
	return head;
}


struct node* inserttail(struct node* head,int x){
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=x;
		head->next=NULL;
		return head;
	}
	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	struct node* newNode=malloc(sizeof(struct node));
	newNode->data=x;
	newNode->next=NULL;
	temp->next=newNode;
	return head;
}
int main(){
	int n,m;
	scanf("%d",&n);
	struct node* h1=NULL;
	struct node* h2=NULL;
	while(n--){
		h1=insertAttail(h1);
	}
	scanf("%d",&m);
	while(m--){
		h2=insertAttail(h2);
	}

	struct node* t1=h1;
	struct node* t2=h2;
	struct node* ans=NULL;
	int carry=0;
	while(t1 && t2){
		int sum=carry+t1->data+t2->data;
		int ud=sum%10;
		carry=sum/10;
		ans=inserttail(ans,ud);
		t1=t1->next;
		t2=t2->next;
	}
	while(t1){
		int sum=carry+t1->data;
		int ud=sum%10;
		carry=sum/10;
		ans=inserttail(ans,ud);
		t1=t1->next;
	}

	while(t2){
		int sum=carry+t2->data;
		int ud=sum%10;
		carry=sum/10;
		ans=inserttail(ans,ud);
		t2=t2->next;
	}

	if(carry>0){
		ans=inserttail(ans,carry);
	}

	struct node* temp=ans;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
	return 0;
}