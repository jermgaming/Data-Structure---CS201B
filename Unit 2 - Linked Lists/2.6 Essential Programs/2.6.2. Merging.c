#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* insertAttaiL(struct node* n1){
	int x;
	scanf("%d",&x);
	if(n1==NULL){
		n1=malloc(sizeof(struct node));
		n1->next=NULL;
		n1->data=x;
		return n1;
	}
	struct node* temp=n1;
	while(temp->next){
		temp=temp->next;
	}
	struct node* newNode=malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->data=x;
	temp->next=newNode;
	return n1;
}

struct node* insertNode(struct node* n1,int x){
	if(n1==NULL){
		n1=malloc(sizeof(struct node));
		n1->next=NULL;
		n1->data=x;
		return n1;
	}
	struct node* temp=n1;
	while(temp->next){
		temp=temp->next;
	}
	struct node* newNode=malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->data=x;
	temp->next=newNode;
	return n1;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	struct node* n1=NULL;
	struct node* n2=NULL;
	while(n--){
		n1=insertAttaiL(n1);
	}

	while(m--){
		n2=insertAttaiL(n2);
	}

	struct node* t1=n1;
	struct node* t2=n2;
	struct node* ans=NULL;
	while(t1!=NULL && t2!=NULL){
		if(t1->data>=t2->data){
			ans=insertNode(ans,t2->data);
			t2=t2->next;
		}else {
			ans=insertNode(ans,t1->data);
			t1=t1->next;
		}
	}

	if(t1==NULL && t2!=NULL){
		while(t2){
			ans=insertNode(ans,t2->data);
			t2=t2->next;
		}
	}

	if(t2==NULL && t1!=NULL){
		while(t1){
			ans=insertNode(ans,t1->data);
			t1=t1->next;
		}
	}
	
	struct node* temp=ans;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
	return 0;
}